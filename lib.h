#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/hash.hpp>

// #define TINYOBJLOADER_IMPLEMENTATION
// #include <tiny_obj_loader.h>

#include <windows.h>

#include <iostream>
#include <fstream>
#include <filesystem>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cstdint>
#include <limits>
#include <optional>
#include <set>
#include <array>
#include <unordered_map>

using namespace std;

// 디버그 모드를 켜면, 에러들을 콘솔에 출력함
#define DEBUG
// #define NDEBUG

#include "Structs.h"
