# Automatically generated makefile, created by the Introjucer
# Don't edit this file! Your changes will be overwritten when you re-save the Introjucer project!

# (this disables dependency generation if multiple architectures are set)
DEPFLAGS := $(if $(word 2, $(TARGET_ARCH)), , -MMD)

ifndef CONFIG
  CONFIG=Debug
endif

ifeq ($(CONFIG),Debug)
  BINDIR := build
  LIBDIR := build
  OBJDIR := build/intermediate/Debug
  OUTDIR := build

  ifeq ($(TARGET_ARCH),)
    TARGET_ARCH := -march=native
  endif

  CPPFLAGS := $(DEPFLAGS) -D "LINUX=1" -D "DEBUG=1" -D "_DEBUG=1" -D "JUCER_LINUX_MAKE_6D53C8B4=1" -D "JUCE_APP_VERSION=1.0.0" -D "JUCE_APP_VERSION_HEX=0x10000" -I /usr/include -I /usr/include/freetype2 -I ../../JuceLibraryCode -I ../../../../../sdks/juce/modules
  CFLAGS += $(CPPFLAGS) $(TARGET_ARCH) -g -ggdb -O0
  CXXFLAGS += $(CFLAGS) -std=c++11
  LDFLAGS += $(TARGET_ARCH) -L$(BINDIR) -L$(LIBDIR) -L/usr/X11R6/lib/ -lGL -lX11 -lXext -lXinerama -lasound -ldl -lfreetype -lpthread -lrt 

  TARGET := Funnel
  BLDCMD = $(CXX) -o $(OUTDIR)/$(TARGET) $(OBJECTS) $(LDFLAGS) $(RESOURCES) $(TARGET_ARCH)
  CLEANCMD = rm -rf $(OUTDIR)/$(TARGET) $(OBJDIR)
endif

ifeq ($(CONFIG),Release)
  BINDIR := build
  LIBDIR := build
  OBJDIR := build/intermediate/Release
  OUTDIR := build

  ifeq ($(TARGET_ARCH),)
    TARGET_ARCH := -march=native
  endif

  CPPFLAGS := $(DEPFLAGS) -D "LINUX=1" -D "NDEBUG=1" -D "JUCER_LINUX_MAKE_6D53C8B4=1" -D "JUCE_APP_VERSION=1.0.0" -D "JUCE_APP_VERSION_HEX=0x10000" -I /usr/include -I /usr/include/freetype2 -I ../../JuceLibraryCode -I ../../../../../sdks/juce/modules
  CFLAGS += $(CPPFLAGS) $(TARGET_ARCH) -O3
  CXXFLAGS += $(CFLAGS) -std=c++11
  LDFLAGS += $(TARGET_ARCH) -L$(BINDIR) -L$(LIBDIR) -fvisibility=hidden -L/usr/X11R6/lib/ -lGL -lX11 -lXext -lXinerama -lasound -ldl -lfreetype -lpthread -lrt 

  TARGET := Funnel
  BLDCMD = $(CXX) -o $(OUTDIR)/$(TARGET) $(OBJECTS) $(LDFLAGS) $(RESOURCES) $(TARGET_ARCH)
  CLEANCMD = rm -rf $(OUTDIR)/$(TARGET) $(OBJDIR)
endif

OBJECTS := \
  $(OBJDIR)/PingButton_1dde8acd.o \
  $(OBJDIR)/OutgoingEditor_4ba76702.o \
  $(OBJDIR)/IncomingEditor_8c070b3c.o \
  $(OBJDIR)/CoreVoice_62c20b4.o \
  $(OBJDIR)/Mixer_d95e2aea.o \
  $(OBJDIR)/Hub_5fe018d6.o \
  $(OBJDIR)/VoiceBank_6e9e10ef.o \
  $(OBJDIR)/Voice_616ec393.o \
  $(OBJDIR)/MainComponent_a6ffb4a5.o \
  $(OBJDIR)/Main_90ebc5c2.o \
  $(OBJDIR)/juce_audio_basics_f3e18a03.o \
  $(OBJDIR)/juce_audio_devices_7526a01.o \
  $(OBJDIR)/juce_audio_formats_35d3b3a1.o \
  $(OBJDIR)/juce_audio_processors_2c79b0bb.o \
  $(OBJDIR)/juce_audio_utils_eb422a41.o \
  $(OBJDIR)/juce_core_3cc78e5.o \
  $(OBJDIR)/juce_cryptography_f5668d3f.o \
  $(OBJDIR)/juce_data_structures_6da182e1.o \
  $(OBJDIR)/juce_events_2fdead9.o \
  $(OBJDIR)/juce_graphics_f98fb5bd.o \
  $(OBJDIR)/juce_gui_basics_9897f6b9.o \
  $(OBJDIR)/juce_gui_extra_f7ca8281.o \
  $(OBJDIR)/juce_opengl_c3461305.o \
  $(OBJDIR)/juce_osc_d4aba321.o \
  $(OBJDIR)/juce_video_ce77b6a1.o \

.PHONY: clean

$(OUTDIR)/$(TARGET): $(OBJECTS) $(RESOURCES)
	@echo Linking Funnel
	-@mkdir -p $(BINDIR)
	-@mkdir -p $(LIBDIR)
	-@mkdir -p $(OUTDIR)
	@$(BLDCMD)

clean:
	@echo Cleaning Funnel
	@$(CLEANCMD)

strip:
	@echo Stripping Funnel
	-@strip --strip-unneeded $(OUTDIR)/$(TARGET)

$(OBJDIR)/PingButton_1dde8acd.o: ../../Source/PingButton.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling PingButton.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/OutgoingEditor_4ba76702.o: ../../Source/OutgoingEditor.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling OutgoingEditor.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/IncomingEditor_8c070b3c.o: ../../Source/IncomingEditor.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling IncomingEditor.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/CoreVoice_62c20b4.o: ../../Source/CoreVoice.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling CoreVoice.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Mixer_d95e2aea.o: ../../Source/Mixer.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Mixer.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Hub_5fe018d6.o: ../../Source/Hub.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Hub.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/VoiceBank_6e9e10ef.o: ../../Source/VoiceBank.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling VoiceBank.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Voice_616ec393.o: ../../Source/Voice.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Voice.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/MainComponent_a6ffb4a5.o: ../../Source/MainComponent.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling MainComponent.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Main_90ebc5c2.o: ../../Source/Main.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Main.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_audio_basics_f3e18a03.o: ../../../../../sdks/juce/modules/juce_audio_basics/juce_audio_basics.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_audio_basics.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_audio_devices_7526a01.o: ../../../../../sdks/juce/modules/juce_audio_devices/juce_audio_devices.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_audio_devices.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_audio_formats_35d3b3a1.o: ../../../../../sdks/juce/modules/juce_audio_formats/juce_audio_formats.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_audio_formats.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_audio_processors_2c79b0bb.o: ../../../../../sdks/juce/modules/juce_audio_processors/juce_audio_processors.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_audio_processors.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_audio_utils_eb422a41.o: ../../../../../sdks/juce/modules/juce_audio_utils/juce_audio_utils.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_audio_utils.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_core_3cc78e5.o: ../../../../../sdks/juce/modules/juce_core/juce_core.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_core.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_cryptography_f5668d3f.o: ../../../../../sdks/juce/modules/juce_cryptography/juce_cryptography.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_cryptography.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_data_structures_6da182e1.o: ../../../../../sdks/juce/modules/juce_data_structures/juce_data_structures.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_data_structures.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_events_2fdead9.o: ../../../../../sdks/juce/modules/juce_events/juce_events.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_events.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_graphics_f98fb5bd.o: ../../../../../sdks/juce/modules/juce_graphics/juce_graphics.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_graphics.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_gui_basics_9897f6b9.o: ../../../../../sdks/juce/modules/juce_gui_basics/juce_gui_basics.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_gui_basics.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_gui_extra_f7ca8281.o: ../../../../../sdks/juce/modules/juce_gui_extra/juce_gui_extra.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_gui_extra.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_opengl_c3461305.o: ../../../../../sdks/juce/modules/juce_opengl/juce_opengl.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_opengl.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_osc_d4aba321.o: ../../../../../sdks/juce/modules/juce_osc/juce_osc.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_osc.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_video_ce77b6a1.o: ../../../../../sdks/juce/modules/juce_video/juce_video.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_video.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

-include $(OBJECTS:%.o=%.d)
