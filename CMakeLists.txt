cmake_minimum_required(VERSION 3.15)
project(Velvete VERSION 1.0.0)
set(FETCHCONTENT_UPDATES_DISCONNECTED ON)
include(FetchContent)
FetchContent_Declare(JUCE
  GIT_REPOSITORY https://github.com/juce-framework/JUCE.git
  GIT_TAG        7.0.9
  GIT_SHALLOW    TRUE)
FetchContent_MakeAvailable(JUCE)
juce_add_plugin(Velvete
    COMPANY_NAME "Archergate"
    IS_SYNTH FALSE NEEDS_MIDI_INPUT FALSE NEEDS_MIDI_OUTPUT FALSE IS_MIDI_EFFECT FALSE
    PLUGIN_MANUFACTURER_CODE VELV
    PLUGIN_CODE ETEV
    FORMATS VST3 Standalone
    PRODUCT_NAME "Velvete")
target_sources(Velvete PRIVATE Source/PluginProcessor.cpp Source/PluginEditor.cpp)
target_compile_definitions(Velvete PUBLIC JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0 JUCE_VST3_CAN_REPLACE_VST2=0)
target_link_libraries(Velvete PRIVATE juce::juce_audio_utils juce::juce_dsp juce::juce_recommended_config_flags)
