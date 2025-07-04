#include "imgui_nvrhi_binding.h"

#include <unordered_map>

const uint8_t spirv_vertex[1240] = {
  0x03, 0x02, 0x23, 0x07, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x0e, 0x00,
  0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x00, 0x02, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x6d, 0x61, 0x69, 0x6e, 0x00, 0x00, 0x00, 0x00,
  0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
  0x05, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00,
  0x03, 0x00, 0x03, 0x00, 0x05, 0x00, 0x00, 0x00, 0x58, 0x02, 0x00, 0x00,
  0x05, 0x00, 0x0a, 0x00, 0x08, 0x00, 0x00, 0x00, 0x74, 0x79, 0x70, 0x65,
  0x2e, 0x50, 0x75, 0x73, 0x68, 0x43, 0x6f, 0x6e, 0x73, 0x74, 0x61, 0x6e,
  0x74, 0x2e, 0x50, 0x75, 0x73, 0x68, 0x43, 0x6f, 0x6e, 0x73, 0x74, 0x61,
  0x6e, 0x74, 0x73, 0x00, 0x06, 0x00, 0x07, 0x00, 0x08, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x67, 0x49, 0x6e, 0x76, 0x53, 0x63, 0x72, 0x65,
  0x65, 0x6e, 0x53, 0x69, 0x7a, 0x65, 0x00, 0x00, 0x06, 0x00, 0x06, 0x00,
  0x08, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x67, 0x53, 0x64, 0x72,
  0x53, 0x63, 0x61, 0x6c, 0x65, 0x00, 0x00, 0x00, 0x06, 0x00, 0x05, 0x00,
  0x08, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x67, 0x49, 0x73, 0x53,
  0x72, 0x67, 0x62, 0x00, 0x05, 0x00, 0x06, 0x00, 0x09, 0x00, 0x00, 0x00,
  0x67, 0x5f, 0x50, 0x75, 0x73, 0x68, 0x43, 0x6f, 0x6e, 0x73, 0x74, 0x61,
  0x6e, 0x74, 0x73, 0x00, 0x05, 0x00, 0x07, 0x00, 0x02, 0x00, 0x00, 0x00,
  0x69, 0x6e, 0x2e, 0x76, 0x61, 0x72, 0x2e, 0x50, 0x4f, 0x53, 0x49, 0x54,
  0x49, 0x4f, 0x4e, 0x30, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x07, 0x00,
  0x03, 0x00, 0x00, 0x00, 0x69, 0x6e, 0x2e, 0x76, 0x61, 0x72, 0x2e, 0x54,
  0x45, 0x58, 0x43, 0x4f, 0x4f, 0x52, 0x44, 0x30, 0x00, 0x00, 0x00, 0x00,
  0x05, 0x00, 0x06, 0x00, 0x04, 0x00, 0x00, 0x00, 0x69, 0x6e, 0x2e, 0x76,
  0x61, 0x72, 0x2e, 0x43, 0x4f, 0x4c, 0x4f, 0x52, 0x30, 0x00, 0x00, 0x00,
  0x05, 0x00, 0x07, 0x00, 0x06, 0x00, 0x00, 0x00, 0x6f, 0x75, 0x74, 0x2e,
  0x76, 0x61, 0x72, 0x2e, 0x54, 0x45, 0x58, 0x43, 0x4f, 0x4f, 0x52, 0x44,
  0x30, 0x00, 0x00, 0x00, 0x05, 0x00, 0x06, 0x00, 0x07, 0x00, 0x00, 0x00,
  0x6f, 0x75, 0x74, 0x2e, 0x76, 0x61, 0x72, 0x2e, 0x43, 0x4f, 0x4c, 0x4f,
  0x52, 0x30, 0x00, 0x00, 0x05, 0x00, 0x04, 0x00, 0x01, 0x00, 0x00, 0x00,
  0x6d, 0x61, 0x69, 0x6e, 0x00, 0x00, 0x00, 0x00, 0x47, 0x00, 0x04, 0x00,
  0x05, 0x00, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x47, 0x00, 0x04, 0x00, 0x02, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x47, 0x00, 0x04, 0x00, 0x03, 0x00, 0x00, 0x00,
  0x1e, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x47, 0x00, 0x04, 0x00,
  0x04, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
  0x47, 0x00, 0x04, 0x00, 0x06, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x47, 0x00, 0x04, 0x00, 0x07, 0x00, 0x00, 0x00,
  0x1e, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x48, 0x00, 0x05, 0x00,
  0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x23, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x48, 0x00, 0x05, 0x00, 0x08, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x23, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00,
  0x48, 0x00, 0x05, 0x00, 0x08, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
  0x23, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x47, 0x00, 0x03, 0x00,
  0x08, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x15, 0x00, 0x04, 0x00,
  0x0a, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
  0x2b, 0x00, 0x04, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x16, 0x00, 0x03, 0x00, 0x0c, 0x00, 0x00, 0x00,
  0x20, 0x00, 0x00, 0x00, 0x2b, 0x00, 0x04, 0x00, 0x0c, 0x00, 0x00, 0x00,
  0x0d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x2b, 0x00, 0x04, 0x00,
  0x0c, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3f,
  0x17, 0x00, 0x04, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00,
  0x02, 0x00, 0x00, 0x00, 0x2c, 0x00, 0x05, 0x00, 0x0f, 0x00, 0x00, 0x00,
  0x10, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00,
  0x2b, 0x00, 0x04, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x05, 0x00, 0x08, 0x00, 0x00, 0x00,
  0x0f, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00,
  0x20, 0x00, 0x04, 0x00, 0x12, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00,
  0x08, 0x00, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00, 0x13, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x17, 0x00, 0x04, 0x00,
  0x14, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
  0x20, 0x00, 0x04, 0x00, 0x15, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
  0x14, 0x00, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00, 0x16, 0x00, 0x00, 0x00,
  0x03, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00,
  0x17, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00,
  0x13, 0x00, 0x02, 0x00, 0x18, 0x00, 0x00, 0x00, 0x21, 0x00, 0x03, 0x00,
  0x19, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00,
  0x1a, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00,
  0x3b, 0x00, 0x04, 0x00, 0x12, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00,
  0x09, 0x00, 0x00, 0x00, 0x3b, 0x00, 0x04, 0x00, 0x13, 0x00, 0x00, 0x00,
  0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x3b, 0x00, 0x04, 0x00,
  0x13, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
  0x3b, 0x00, 0x04, 0x00, 0x15, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x3b, 0x00, 0x04, 0x00, 0x16, 0x00, 0x00, 0x00,
  0x05, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x3b, 0x00, 0x04, 0x00,
  0x17, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
  0x3b, 0x00, 0x04, 0x00, 0x16, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00,
  0x03, 0x00, 0x00, 0x00, 0x36, 0x00, 0x05, 0x00, 0x18, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x19, 0x00, 0x00, 0x00,
  0xf8, 0x00, 0x02, 0x00, 0x1b, 0x00, 0x00, 0x00, 0x3d, 0x00, 0x04, 0x00,
  0x0f, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
  0x3d, 0x00, 0x04, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x1d, 0x00, 0x00, 0x00,
  0x03, 0x00, 0x00, 0x00, 0x3d, 0x00, 0x04, 0x00, 0x14, 0x00, 0x00, 0x00,
  0x1e, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x41, 0x00, 0x05, 0x00,
  0x1a, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00,
  0x0b, 0x00, 0x00, 0x00, 0x3d, 0x00, 0x04, 0x00, 0x0f, 0x00, 0x00, 0x00,
  0x20, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x85, 0x00, 0x05, 0x00,
  0x0f, 0x00, 0x00, 0x00, 0x21, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00,
  0x20, 0x00, 0x00, 0x00, 0x8e, 0x00, 0x05, 0x00, 0x0f, 0x00, 0x00, 0x00,
  0x22, 0x00, 0x00, 0x00, 0x21, 0x00, 0x00, 0x00, 0x0d, 0x00, 0x00, 0x00,
  0x83, 0x00, 0x05, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x23, 0x00, 0x00, 0x00,
  0x22, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x51, 0x00, 0x05, 0x00,
  0x0c, 0x00, 0x00, 0x00, 0x24, 0x00, 0x00, 0x00, 0x23, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x7f, 0x00, 0x04, 0x00, 0x0c, 0x00, 0x00, 0x00,
  0x25, 0x00, 0x00, 0x00, 0x24, 0x00, 0x00, 0x00, 0x51, 0x00, 0x05, 0x00,
  0x0c, 0x00, 0x00, 0x00, 0x26, 0x00, 0x00, 0x00, 0x23, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x50, 0x00, 0x07, 0x00, 0x14, 0x00, 0x00, 0x00,
  0x27, 0x00, 0x00, 0x00, 0x26, 0x00, 0x00, 0x00, 0x25, 0x00, 0x00, 0x00,
  0x11, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x3e, 0x00, 0x03, 0x00,
  0x05, 0x00, 0x00, 0x00, 0x27, 0x00, 0x00, 0x00, 0x3e, 0x00, 0x03, 0x00,
  0x06, 0x00, 0x00, 0x00, 0x1d, 0x00, 0x00, 0x00, 0x3e, 0x00, 0x03, 0x00,
  0x07, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0xfd, 0x00, 0x01, 0x00,
  0x38, 0x00, 0x01, 0x00
};

const uint8_t spirv_fragment[1680] = {
  0x03, 0x02, 0x23, 0x07, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x0e, 0x00,
  0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x00, 0x02, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x0b, 0x00, 0x06, 0x00, 0x01, 0x00, 0x00, 0x00,
  0x47, 0x4c, 0x53, 0x4c, 0x2e, 0x73, 0x74, 0x64, 0x2e, 0x34, 0x35, 0x30,
  0x00, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x08, 0x00, 0x04, 0x00, 0x00, 0x00,
  0x02, 0x00, 0x00, 0x00, 0x6d, 0x61, 0x69, 0x6e, 0x00, 0x00, 0x00, 0x00,
  0x03, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00,
  0x10, 0x00, 0x03, 0x00, 0x02, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00,
  0x03, 0x00, 0x03, 0x00, 0x05, 0x00, 0x00, 0x00, 0x58, 0x02, 0x00, 0x00,
  0x05, 0x00, 0x0a, 0x00, 0x06, 0x00, 0x00, 0x00, 0x74, 0x79, 0x70, 0x65,
  0x2e, 0x50, 0x75, 0x73, 0x68, 0x43, 0x6f, 0x6e, 0x73, 0x74, 0x61, 0x6e,
  0x74, 0x2e, 0x50, 0x75, 0x73, 0x68, 0x43, 0x6f, 0x6e, 0x73, 0x74, 0x61,
  0x6e, 0x74, 0x73, 0x00, 0x06, 0x00, 0x07, 0x00, 0x06, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x67, 0x49, 0x6e, 0x76, 0x53, 0x63, 0x72, 0x65,
  0x65, 0x6e, 0x53, 0x69, 0x7a, 0x65, 0x00, 0x00, 0x06, 0x00, 0x06, 0x00,
  0x06, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x67, 0x53, 0x64, 0x72,
  0x53, 0x63, 0x61, 0x6c, 0x65, 0x00, 0x00, 0x00, 0x06, 0x00, 0x05, 0x00,
  0x06, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x67, 0x49, 0x73, 0x53,
  0x72, 0x67, 0x62, 0x00, 0x05, 0x00, 0x06, 0x00, 0x07, 0x00, 0x00, 0x00,
  0x67, 0x5f, 0x50, 0x75, 0x73, 0x68, 0x43, 0x6f, 0x6e, 0x73, 0x74, 0x61,
  0x6e, 0x74, 0x73, 0x00, 0x05, 0x00, 0x06, 0x00, 0x08, 0x00, 0x00, 0x00,
  0x74, 0x79, 0x70, 0x65, 0x2e, 0x73, 0x61, 0x6d, 0x70, 0x6c, 0x65, 0x72,
  0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x05, 0x00, 0x09, 0x00, 0x00, 0x00,
  0x73, 0x61, 0x6d, 0x70, 0x6c, 0x65, 0x72, 0x30, 0x00, 0x00, 0x00, 0x00,
  0x05, 0x00, 0x06, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x74, 0x79, 0x70, 0x65,
  0x2e, 0x32, 0x64, 0x2e, 0x69, 0x6d, 0x61, 0x67, 0x65, 0x00, 0x00, 0x00,
  0x05, 0x00, 0x05, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x74, 0x65, 0x78, 0x74,
  0x75, 0x72, 0x65, 0x30, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x07, 0x00,
  0x03, 0x00, 0x00, 0x00, 0x69, 0x6e, 0x2e, 0x76, 0x61, 0x72, 0x2e, 0x54,
  0x45, 0x58, 0x43, 0x4f, 0x4f, 0x52, 0x44, 0x30, 0x00, 0x00, 0x00, 0x00,
  0x05, 0x00, 0x06, 0x00, 0x04, 0x00, 0x00, 0x00, 0x69, 0x6e, 0x2e, 0x76,
  0x61, 0x72, 0x2e, 0x43, 0x4f, 0x4c, 0x4f, 0x52, 0x30, 0x00, 0x00, 0x00,
  0x05, 0x00, 0x07, 0x00, 0x05, 0x00, 0x00, 0x00, 0x6f, 0x75, 0x74, 0x2e,
  0x76, 0x61, 0x72, 0x2e, 0x53, 0x56, 0x5f, 0x54, 0x61, 0x72, 0x67, 0x65,
  0x74, 0x00, 0x00, 0x00, 0x05, 0x00, 0x04, 0x00, 0x02, 0x00, 0x00, 0x00,
  0x6d, 0x61, 0x69, 0x6e, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x07, 0x00,
  0x0c, 0x00, 0x00, 0x00, 0x74, 0x79, 0x70, 0x65, 0x2e, 0x73, 0x61, 0x6d,
  0x70, 0x6c, 0x65, 0x64, 0x2e, 0x69, 0x6d, 0x61, 0x67, 0x65, 0x00, 0x00,
  0x47, 0x00, 0x04, 0x00, 0x03, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x47, 0x00, 0x04, 0x00, 0x04, 0x00, 0x00, 0x00,
  0x1e, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x47, 0x00, 0x04, 0x00,
  0x05, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x47, 0x00, 0x04, 0x00, 0x09, 0x00, 0x00, 0x00, 0x22, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x47, 0x00, 0x04, 0x00, 0x09, 0x00, 0x00, 0x00,
  0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x47, 0x00, 0x04, 0x00,
  0x0b, 0x00, 0x00, 0x00, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x47, 0x00, 0x04, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x21, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x48, 0x00, 0x05, 0x00, 0x06, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x23, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x48, 0x00, 0x05, 0x00, 0x06, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
  0x23, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x48, 0x00, 0x05, 0x00,
  0x06, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x23, 0x00, 0x00, 0x00,
  0x0c, 0x00, 0x00, 0x00, 0x47, 0x00, 0x03, 0x00, 0x06, 0x00, 0x00, 0x00,
  0x02, 0x00, 0x00, 0x00, 0x15, 0x00, 0x04, 0x00, 0x0d, 0x00, 0x00, 0x00,
  0x20, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x2b, 0x00, 0x04, 0x00,
  0x0d, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
  0x2b, 0x00, 0x04, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x16, 0x00, 0x03, 0x00, 0x10, 0x00, 0x00, 0x00,
  0x20, 0x00, 0x00, 0x00, 0x2b, 0x00, 0x04, 0x00, 0x10, 0x00, 0x00, 0x00,
  0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x17, 0x00, 0x04, 0x00,
  0x12, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
  0x1e, 0x00, 0x05, 0x00, 0x06, 0x00, 0x00, 0x00, 0x12, 0x00, 0x00, 0x00,
  0x10, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00,
  0x13, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00,
  0x1a, 0x00, 0x02, 0x00, 0x08, 0x00, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00,
  0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00,
  0x19, 0x00, 0x09, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x20, 0x00, 0x04, 0x00, 0x15, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x0a, 0x00, 0x00, 0x00, 0x17, 0x00, 0x04, 0x00, 0x16, 0x00, 0x00, 0x00,
  0x10, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00,
  0x17, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x16, 0x00, 0x00, 0x00,
  0x20, 0x00, 0x04, 0x00, 0x18, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
  0x12, 0x00, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00, 0x19, 0x00, 0x00, 0x00,
  0x03, 0x00, 0x00, 0x00, 0x16, 0x00, 0x00, 0x00, 0x13, 0x00, 0x02, 0x00,
  0x1a, 0x00, 0x00, 0x00, 0x21, 0x00, 0x03, 0x00, 0x1b, 0x00, 0x00, 0x00,
  0x1a, 0x00, 0x00, 0x00, 0x1b, 0x00, 0x03, 0x00, 0x0c, 0x00, 0x00, 0x00,
  0x0a, 0x00, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00, 0x1c, 0x00, 0x00, 0x00,
  0x09, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x14, 0x00, 0x02, 0x00,
  0x1d, 0x00, 0x00, 0x00, 0x17, 0x00, 0x04, 0x00, 0x1e, 0x00, 0x00, 0x00,
  0x10, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x3b, 0x00, 0x04, 0x00,
  0x13, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00,
  0x3b, 0x00, 0x04, 0x00, 0x14, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x3b, 0x00, 0x04, 0x00, 0x15, 0x00, 0x00, 0x00,
  0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3b, 0x00, 0x04, 0x00,
  0x18, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
  0x3b, 0x00, 0x04, 0x00, 0x17, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x3b, 0x00, 0x04, 0x00, 0x19, 0x00, 0x00, 0x00,
  0x05, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x36, 0x00, 0x05, 0x00,
  0x1a, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x1b, 0x00, 0x00, 0x00, 0xf8, 0x00, 0x02, 0x00, 0x1f, 0x00, 0x00, 0x00,
  0x3d, 0x00, 0x04, 0x00, 0x12, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00,
  0x03, 0x00, 0x00, 0x00, 0x3d, 0x00, 0x04, 0x00, 0x16, 0x00, 0x00, 0x00,
  0x21, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x3d, 0x00, 0x04, 0x00,
  0x0a, 0x00, 0x00, 0x00, 0x22, 0x00, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00,
  0x3d, 0x00, 0x04, 0x00, 0x08, 0x00, 0x00, 0x00, 0x23, 0x00, 0x00, 0x00,
  0x09, 0x00, 0x00, 0x00, 0x56, 0x00, 0x05, 0x00, 0x0c, 0x00, 0x00, 0x00,
  0x24, 0x00, 0x00, 0x00, 0x22, 0x00, 0x00, 0x00, 0x23, 0x00, 0x00, 0x00,
  0x57, 0x00, 0x06, 0x00, 0x16, 0x00, 0x00, 0x00, 0x25, 0x00, 0x00, 0x00,
  0x24, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x51, 0x00, 0x05, 0x00, 0x10, 0x00, 0x00, 0x00, 0x26, 0x00, 0x00, 0x00,
  0x25, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x51, 0x00, 0x05, 0x00,
  0x10, 0x00, 0x00, 0x00, 0x27, 0x00, 0x00, 0x00, 0x21, 0x00, 0x00, 0x00,
  0x03, 0x00, 0x00, 0x00, 0x85, 0x00, 0x05, 0x00, 0x10, 0x00, 0x00, 0x00,
  0x28, 0x00, 0x00, 0x00, 0x27, 0x00, 0x00, 0x00, 0x26, 0x00, 0x00, 0x00,
  0x52, 0x00, 0x06, 0x00, 0x16, 0x00, 0x00, 0x00, 0x29, 0x00, 0x00, 0x00,
  0x28, 0x00, 0x00, 0x00, 0x21, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
  0x41, 0x00, 0x05, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x2a, 0x00, 0x00, 0x00,
  0x07, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x3d, 0x00, 0x04, 0x00,
  0x10, 0x00, 0x00, 0x00, 0x2b, 0x00, 0x00, 0x00, 0x2a, 0x00, 0x00, 0x00,
  0xb4, 0x00, 0x05, 0x00, 0x1d, 0x00, 0x00, 0x00, 0x2c, 0x00, 0x00, 0x00,
  0x2b, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 0xf7, 0x00, 0x03, 0x00,
  0x2d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfa, 0x00, 0x04, 0x00,
  0x2c, 0x00, 0x00, 0x00, 0x2e, 0x00, 0x00, 0x00, 0x2d, 0x00, 0x00, 0x00,
  0xf8, 0x00, 0x02, 0x00, 0x2e, 0x00, 0x00, 0x00, 0x4f, 0x00, 0x08, 0x00,
  0x1e, 0x00, 0x00, 0x00, 0x2f, 0x00, 0x00, 0x00, 0x29, 0x00, 0x00, 0x00,
  0x29, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
  0x02, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x06, 0x00, 0x1e, 0x00, 0x00, 0x00,
  0x30, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x00,
  0x2f, 0x00, 0x00, 0x00, 0x4f, 0x00, 0x09, 0x00, 0x16, 0x00, 0x00, 0x00,
  0x31, 0x00, 0x00, 0x00, 0x29, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00,
  0x04, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00,
  0x03, 0x00, 0x00, 0x00, 0xf9, 0x00, 0x02, 0x00, 0x2d, 0x00, 0x00, 0x00,
  0xf8, 0x00, 0x02, 0x00, 0x2d, 0x00, 0x00, 0x00, 0xf5, 0x00, 0x07, 0x00,
  0x16, 0x00, 0x00, 0x00, 0x32, 0x00, 0x00, 0x00, 0x29, 0x00, 0x00, 0x00,
  0x1f, 0x00, 0x00, 0x00, 0x31, 0x00, 0x00, 0x00, 0x2e, 0x00, 0x00, 0x00,
  0x41, 0x00, 0x05, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x33, 0x00, 0x00, 0x00,
  0x07, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x3d, 0x00, 0x04, 0x00,
  0x10, 0x00, 0x00, 0x00, 0x34, 0x00, 0x00, 0x00, 0x33, 0x00, 0x00, 0x00,
  0x4f, 0x00, 0x08, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x35, 0x00, 0x00, 0x00,
  0x32, 0x00, 0x00, 0x00, 0x32, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x8e, 0x00, 0x05, 0x00,
  0x1e, 0x00, 0x00, 0x00, 0x36, 0x00, 0x00, 0x00, 0x35, 0x00, 0x00, 0x00,
  0x34, 0x00, 0x00, 0x00, 0x4f, 0x00, 0x09, 0x00, 0x16, 0x00, 0x00, 0x00,
  0x37, 0x00, 0x00, 0x00, 0x32, 0x00, 0x00, 0x00, 0x36, 0x00, 0x00, 0x00,
  0x04, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00,
  0x03, 0x00, 0x00, 0x00, 0x3e, 0x00, 0x03, 0x00, 0x05, 0x00, 0x00, 0x00,
  0x37, 0x00, 0x00, 0x00, 0xfd, 0x00, 0x01, 0x00, 0x38, 0x00, 0x01, 0x00
};

struct VERTEX_CONSTANT_BUFFER
{
    float        mvp[4][4];
};

struct ImGui_ImplNVRHI
{
    bool UpdateFontTexture()
    {
        ImGuiIO& io = ImGui::GetIO();

        // If the font texture exists and is bound to ImGui, we're done.
        // Note: ImGui_Renderer will reset io.Fonts->TexID when new fonts are added.
        if (fontTexture && io.Fonts->TexID)
            return true;

        unsigned char* pixels;
        int width, height;

        io.Fonts->GetTexDataAsRGBA32(&pixels, &width, &height);
        if (!pixels)
            return false;

        nvrhi::TextureDesc textureDesc;
        textureDesc.width = width;
        textureDesc.height = height;
        textureDesc.format = nvrhi::Format::RGBA8_UNORM;
        textureDesc.debugName = "ImGui font texture";

        fontTexture = m_device->createTexture(textureDesc);
        if (fontTexture == nullptr)
            return false;

        m_commandList->open();

        m_commandList->beginTrackingTextureState(fontTexture, nvrhi::AllSubresources, nvrhi::ResourceStates::Common);

        m_commandList->writeTexture(fontTexture, 0, 0, pixels, width * 4);

        m_commandList->setPermanentTextureState(fontTexture, nvrhi::ResourceStates::ShaderResource);
        m_commandList->commitBarriers();

        m_commandList->close();
        m_device->executeCommandList(m_commandList);

        io.Fonts->TexID = (ImTextureID)fontTexture.Get();

        return true;
    }

    bool Init(nvrhi::IDevice* device)
    {
        m_device = device;

        m_commandList = m_device->createCommandList();

        auto vertexDesc = nvrhi::ShaderDesc()
            .setEntryName("main")
            .setShaderType(nvrhi::ShaderType::Vertex);

        vertexShader = device->createShader(vertexDesc, spirv_vertex, sizeof(spirv_vertex));

        auto pixelDesc = nvrhi::ShaderDesc()
            .setEntryName("main")
            .setShaderType(nvrhi::ShaderType::Pixel);

        pixelShader = device->createShader(pixelDesc, spirv_fragment, sizeof(spirv_fragment));

        if (!vertexShader || !pixelShader)
            return false;

        // create attribute layout object
        nvrhi::VertexAttributeDesc vertexAttribLayout[] = {
            { "POSITION", nvrhi::Format::RG32_FLOAT,  1, 0, 0, sizeof(ImDrawVert), false },
            { "TEXCOORD", nvrhi::Format::RG32_FLOAT,  1, 0, sizeof(ImVec2),  sizeof(ImDrawVert), false },
            { "COLOR",    nvrhi::Format::RGBA8_UNORM, 1, 0, sizeof(ImVec2) * 2, sizeof(ImDrawVert), false },
        };

        shaderAttribLayout = m_device->createInputLayout(vertexAttribLayout, sizeof(vertexAttribLayout) / sizeof(vertexAttribLayout[0]), vertexShader);

        // create PSO
        {
            nvrhi::BlendState blendState;
            blendState.targets[0].setBlendEnable(true)
                .setSrcBlend(nvrhi::BlendFactor::SrcAlpha)
                .setDestBlend(nvrhi::BlendFactor::InvSrcAlpha)
                .setSrcBlendAlpha(nvrhi::BlendFactor::InvSrcAlpha)
                .setDestBlendAlpha(nvrhi::BlendFactor::Zero);

            auto rasterState = nvrhi::RasterState()
                .setFillSolid()
                .setCullNone()
                .setScissorEnable(true)
                .setDepthClipEnable(true);

            auto depthStencilState = nvrhi::DepthStencilState()
                .disableDepthTest()
                .enableDepthWrite()
                .disableStencil()
                .setDepthFunc(nvrhi::ComparisonFunc::Always);

            nvrhi::RenderState renderState;
            renderState.blendState = blendState;
            renderState.depthStencilState = depthStencilState;
            renderState.rasterState = rasterState;

            nvrhi::BindingLayoutDesc layoutDesc;
            layoutDesc.visibility = nvrhi::ShaderType::All;
            layoutDesc.bindings = {
                nvrhi::BindingLayoutItem::PushConstants(0, sizeof(float) * 2),
                nvrhi::BindingLayoutItem::Texture_SRV(0),
                nvrhi::BindingLayoutItem::Sampler(0)
            };
            bindingLayout = m_device->createBindingLayout(layoutDesc);

            basePSODesc.primType = nvrhi::PrimitiveType::TriangleList;
            basePSODesc.inputLayout = shaderAttribLayout;
            basePSODesc.VS = vertexShader;
            basePSODesc.PS = pixelShader;
            basePSODesc.renderState = renderState;
            basePSODesc.bindingLayouts = { bindingLayout };
        }

        {
            const auto desc = nvrhi::SamplerDesc()
                .setAllAddressModes(nvrhi::SamplerAddressMode::Wrap)
                .setAllFilters(true);

            fontSampler = m_device->createSampler(desc);

            if (fontSampler == nullptr)
                return false;
        }

        return true;
    }

    bool Render(nvrhi::IFramebuffer* framebuffer, ImDrawData* drawData)
    {
        const auto& io = ImGui::GetIO();

        m_commandList->open();
        m_commandList->beginMarker("ImGUI");

        if (!UpdateGeometry(m_commandList))
        {
            m_commandList->close();
            return false;
        }

        // handle DPI scaling
        drawData->ScaleClipRects(io.DisplayFramebufferScale);

        float invDisplaySize[2] = { 1.f / io.DisplaySize.x, 1.f / io.DisplaySize.y };

        // set up graphics state
        nvrhi::GraphicsState drawState;

        drawState.framebuffer = framebuffer;
        //assert( drawState.framebuffer );

        drawState.pipeline = GetPSO(drawState.framebuffer);

        drawState.viewport.viewports.push_back(nvrhi::Viewport(io.DisplaySize.x * io.DisplayFramebufferScale.x, io.DisplaySize.y * io.DisplayFramebufferScale.y));
        drawState.viewport.scissorRects.resize(1);  // updated below

        nvrhi::VertexBufferBinding vbufBinding;
        vbufBinding.buffer = vertexBuffer;
        vbufBinding.slot = 0;
        vbufBinding.offset = 0;
        drawState.vertexBuffers.push_back(vbufBinding);

        drawState.indexBuffer.buffer = indexBuffer;
        drawState.indexBuffer.format = (sizeof(ImDrawIdx) == 2 ? nvrhi::Format::R16_UINT : nvrhi::Format::R32_UINT);
        drawState.indexBuffer.offset = 0;

        // render command lists
        int vtxOffset = 0;
        int idxOffset = 0;
        for (int n = 0; n < drawData->CmdListsCount; n++)
        {
            const ImDrawList* cmdList = drawData->CmdLists[n];
            for (int i = 0; i < cmdList->CmdBuffer.Size; i++)
            {
                const ImDrawCmd* pCmd = &cmdList->CmdBuffer[i];

                if (pCmd->UserCallback)
                {
                    pCmd->UserCallback(cmdList, pCmd);
                }
                else
                {
                    drawState.bindings = { GetBindingSet((nvrhi::ITexture*)pCmd->TextureId) };
                    //assert( drawState.bindings[ 0 ] );

                    drawState.viewport.scissorRects[0] = nvrhi::Rect(int(pCmd->ClipRect.x),
                        int(pCmd->ClipRect.z),
                        int(pCmd->ClipRect.y),
                        int(pCmd->ClipRect.w));

                    nvrhi::DrawArguments drawArguments;
                    drawArguments.vertexCount = pCmd->ElemCount;
                    drawArguments.startIndexLocation = idxOffset;
                    drawArguments.startVertexLocation = vtxOffset;

                    m_commandList->setGraphicsState(drawState);
                    m_commandList->setPushConstants(invDisplaySize, sizeof(invDisplaySize));
                    m_commandList->drawIndexed(drawArguments);
                }

                idxOffset += pCmd->ElemCount;
            }

            vtxOffset += cmdList->VtxBuffer.Size;
        }

        m_commandList->endMarker();
        m_commandList->close();
        m_device->executeCommandList(m_commandList);

        return true;
    }

    void BackbufferResizing()
    {
        pso = nullptr;
    }

private:
    bool ReallocateBuffer(nvrhi::BufferHandle& buffer, size_t requiredSize, size_t reallocateSize, const bool indexBuffer)
    {
        if (buffer == nullptr || size_t(buffer->getDesc().byteSize) < requiredSize)
        {
            nvrhi::BufferDesc desc;
            desc.byteSize = uint32_t(reallocateSize);
            desc.structStride = 0;
            desc.debugName = indexBuffer ? "ImGui index buffer" : "ImGui vertex buffer";
            desc.canHaveUAVs = false;
            desc.isVertexBuffer = !indexBuffer;
            desc.isIndexBuffer = indexBuffer;
            desc.isDrawIndirectArgs = false;
            desc.isVolatile = false;
            desc.initialState = indexBuffer ? nvrhi::ResourceStates::IndexBuffer : nvrhi::ResourceStates::VertexBuffer;
            desc.keepInitialState = true;

            buffer = m_device->createBuffer(desc);

            if (!buffer)
            {
                return false;
            }
        }

        return true;
    }

    nvrhi::IGraphicsPipeline* GetPSO(nvrhi::IFramebuffer* fb)
    {
        if (pso)
            return pso;

        pso = m_device->createGraphicsPipeline(basePSODesc, fb);
        //assert( pso );

        return pso;
    }

    nvrhi::IBindingSet* GetBindingSet(nvrhi::ITexture* texture)
    {
        auto iter = bindingsCache.find(texture);
        if (iter != bindingsCache.end())
        {
            return iter->second;
        }

        nvrhi::BindingSetDesc desc;

        desc.bindings = {
            nvrhi::BindingSetItem::PushConstants(0, sizeof(float) * 2),
            nvrhi::BindingSetItem::Texture_SRV(0, texture),
            nvrhi::BindingSetItem::Sampler(0, fontSampler)
        };

        nvrhi::BindingSetHandle binding;
        binding = m_device->createBindingSet(desc, bindingLayout);
        //assert( binding );

        bindingsCache[texture] = binding;
        return binding;
    }

    bool UpdateGeometry(nvrhi::ICommandList* commandList)
    {
        ImDrawData* drawData = ImGui::GetDrawData();

        // create/resize vertex and index buffers if needed
        if (!ReallocateBuffer(vertexBuffer,
            drawData->TotalVtxCount * sizeof(ImDrawVert),
            (drawData->TotalVtxCount + 5000) * sizeof(ImDrawVert),
            false))
        {
            return false;
        }

        if (!ReallocateBuffer(indexBuffer,
            drawData->TotalIdxCount * sizeof(ImDrawIdx),
            (drawData->TotalIdxCount + 5000) * sizeof(ImDrawIdx),
            true))
        {
            return false;
        }

        vtxBuffer.resize(vertexBuffer->getDesc().byteSize / sizeof(ImDrawVert));
        idxBuffer.resize(indexBuffer->getDesc().byteSize / sizeof(ImDrawIdx));

        // copy and convert all vertices into a single contiguous buffer
        ImDrawVert* vtxDst = &vtxBuffer[0];
        ImDrawIdx* idxDst = &idxBuffer[0];

        for (int n = 0; n < drawData->CmdListsCount; n++)
        {
            const ImDrawList* cmdList = drawData->CmdLists[n];

            memcpy(vtxDst, cmdList->VtxBuffer.Data, cmdList->VtxBuffer.Size * sizeof(ImDrawVert));
            memcpy(idxDst, cmdList->IdxBuffer.Data, cmdList->IdxBuffer.Size * sizeof(ImDrawIdx));

            vtxDst += cmdList->VtxBuffer.Size;
            idxDst += cmdList->IdxBuffer.Size;
        }

        commandList->writeBuffer(vertexBuffer, &vtxBuffer[0], vertexBuffer->getDesc().byteSize);
        commandList->writeBuffer(indexBuffer, &idxBuffer[0], indexBuffer->getDesc().byteSize);

        return true;
    }

    nvrhi::DeviceHandle m_device;
    nvrhi::CommandListHandle m_commandList;

    nvrhi::ShaderHandle vertexShader;
    nvrhi::ShaderHandle pixelShader;
    nvrhi::InputLayoutHandle shaderAttribLayout;

    nvrhi::TextureHandle fontTexture;
    nvrhi::SamplerHandle fontSampler;

    nvrhi::BufferHandle vertexBuffer;
    nvrhi::BufferHandle indexBuffer;

    nvrhi::BindingLayoutHandle bindingLayout;
    nvrhi::GraphicsPipelineDesc basePSODesc;

    nvrhi::GraphicsPipelineHandle pso;
    std::unordered_map<nvrhi::ITexture*, nvrhi::BindingSetHandle> bindingsCache;

    std::vector<ImDrawVert> vtxBuffer;
    std::vector<ImDrawIdx> idxBuffer;

};

static ImGui_ImplNVRHI* GetBackendRendererImpl()
{
    ImGuiIO& io = ImGui::GetIO();
    return (ImGui_ImplNVRHI*)io.BackendRendererUserData;
}

bool ImGui_ImplNVRHI_Init(nvrhi::IDevice* device)
{
    ImGuiIO& io = ImGui::GetIO();
    IMGUI_CHECKVERSION();
    IM_ASSERT(io.BackendRendererUserData == nullptr && "Already initialized a renderer backend!");

    // Setup backend capabilities flags
    io.BackendRendererUserData = new ImGui_ImplNVRHI();
    io.BackendRendererName = "imgui_impl_nvrhi";
    io.BackendFlags |= ImGuiBackendFlags_RendererHasVtxOffset;  // We can honor the ImDrawCmd::VtxOffset field, allowing for large meshes.

    return GetBackendRendererImpl()->Init(device);
}

bool ImGui_ImplNVRHI_UpdateFontTexture()
{
    return GetBackendRendererImpl()->UpdateFontTexture();
}

void ImGui_ImplNVRHI_RenderDrawData(ImDrawData* draw_data, nvrhi::IFramebuffer* buffer)
{
    GetBackendRendererImpl()->Render(buffer, draw_data);
}

void ImGui_ImplNVRHI_Shutdown()
{
}
