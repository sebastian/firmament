ROOT_DIR=../..
SUFFIX=engine

include $(ROOT_DIR)/include/Makefile.config
include $(ROOT_DIR)/include/Makefile.common

BINS = coordinator worker
OBJS = coordinator.o worker.o
PBS =
TESTS = coordinator_test worker_test
TESTS_DEPS = $(BUILD_DIR)/platforms/common.pb.o $(BUILD_DIR)/platforms/unix/messaging_streamsockets.o

OBJ_BIN = $(addprefix $(OBJ_DIR)/, $(BINS))
#TESTS_OBJS = $(addprefix $(TEST_OBJ_DIR)/, $(TESTS))
TESTS_BIN = $(addprefix $(TEST_OBJ_DIR)/, $(TESTS))

all: $(OBJ_BIN) $(TESTS_BIN) .setup

# TODO: check if any of the below targets can make use of a generic
# build rule from Makefile.common, or can be converted to do so.

$(OBJ_DIR)/coordinator: $(addprefix $(OBJ_DIR)/, $(OBJS))
	$(call quiet-command, \
		$(CXX) $(CPPFLAGS) \
		$(SRC_ROOT_DIR)/engine/coordinator_main.cc \
		$(CXXFLAGS) $(BUILD_DIR)/base/libfirmament_base.a \
		$(BUILD_DIR)/engine/coordinator.o \
		$(BUILD_DIR)/platforms/common.pb.o \
		$(BUILD_DIR)/platforms/unix/messaging_streamsockets.o \
		$(LIBS) -o $(BUILD_DIR)/engine/coordinator, \
		"  DYNLNK  $(BUILD_DIR)/engine/coordinator")

$(OBJ_DIR)/worker: $(addprefix $(OBJ_DIR)/, $(OBJS))
	$(call quiet-command, \
		$(CXX) $(CPPFLAGS) $(SRC_ROOT_DIR)/engine/worker_main.cc \
		$(CXXFLAGS) $(BUILD_DIR)/base/libfirmament_base.a \
		$(BUILD_DIR)/engine/worker.o \
		$(BUILD_DIR)/platforms/common.pb.o \
		$(BUILD_DIR)/platforms/unix/messaging_streamsockets.o \
		$(LIBS) -o $(BUILD_DIR)/engine/worker, \
		"  DYNLNK  $(BUILD_DIR)/engine/worker")
