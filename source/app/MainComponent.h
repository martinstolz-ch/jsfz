/**
 * (c) martin stolz @ noizplay
 */

#pragma once

#include <JuceHeader.h>

#include "../common/cmake_var.h"
#include "../common/config.h"

#include "../process/Sequencer.h"
#include "../process/Parser.h"

namespace jsfz {

class MainComponent final
    : public AudioAppComponent {

public:
    MainComponent() {

        setSize(400, 300);

        // Button setup
        _loadSfzButton.setButtonText("Load SFZ");
        _loadSfzButton.onClick = [this] { loadSfzFile(); };
        addAndMakeVisible(_loadSfzButton);

        // File chooser setup
        _fileChooser = std::make_unique<FileChooser>(
            "Select SFZ file",
            File::getSpecialLocation(File::userMusicDirectory),
            "*.sfz"
        );

        ///

        // Some platforms require permissions to open input channels so request that here
        if ( RuntimePermissions::isRequired (RuntimePermissions::recordAudio)
             &&
             ! RuntimePermissions::isGranted (RuntimePermissions::recordAudio)) {

            RuntimePermissions::request (RuntimePermissions::recordAudio,
                                               [&] (bool granted) {
                                                   setAudioChannels (granted ? 2 : 0, 2);
                                               }

            );
             } else {

                 // Specify the number of input and output channels that we want to open
                 setAudioChannels (2, 2);
             }

        const auto file {File{"/Users/martinstolz/Desktop/F.sfz"}};
        const auto sfzContent = file.loadFileAsString();
        DBG("SFZ Content:\n" + sfzContent);
        DBG("parser ends with " << val(_parser.process(sfzContent.toWideCharPointer())));

    }

    ~MainComponent() override {
        shutdownAudio();
    }

    void paint(Graphics& g) override {
        g.setColour(config::mainColour);
        g.setFont (FontOptions().withStyle ("light"));
        g.drawFittedText(
                cmake_var::companyURL,
                getLocalBounds(),
                Justification::centredBottom,
                1);
    }

    void resized() override {
        auto bounds = getLocalBounds();
        bounds.reduce(20, 20);

        _loadSfzButton.setBounds(bounds.removeFromTop(40));
    }

    /**
     * Prepares the audio processor for play by setting up the necessary sample rate, block size,
     * and performing any initialization required before audio playback or processing begins.
     *
     * @param sampleRate The sample rate at which the processor will operate, typically in Hz (e.g., 44100, 48000).
     * @param samplesPerBlockExpected The number of samples per audio processing block. This value dictates the buffer size being processed at a time.
     */

    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override {
        ignoreUnused(samplesPerBlockExpected, sampleRate); // avoid warning
        // ...
    }

    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override {
        ignoreUnused(bufferToFill); // avoid warning
        bufferToFill.clearActiveBufferRegion();
    }

    void releaseResources() override {
        // ...
    }

private:

    void loadSfzFile() {
        /*
        _fileChooser->launchAsync(
            FileBrowserComponent::openMode | FileBrowserComponent::canSelectFiles,
            [this](const FileChooser& chooser) {
                if (const auto file = chooser.getResult(); file.existsAsFile()) {
                    const auto sfzContent = file.loadFileAsString();
                    DBG("SFZ File loaded: " + file.getFileName());
                    DBG("Content length: " + String(sfzContent.length()) + " chars");
                    DBG("SFZ Content:\n" + sfzContent);
                    _parser.process(sfzContent.toWideCharPointer());
                }
            }
        );
        */
    }

    TextButton                   _loadSfzButton;
    std::unique_ptr<FileChooser> _fileChooser;

    Sequencer _sequencer{};
    Parser    _parser{_sequencer};

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR( MainComponent )
};

}