실행 코드

C:/mingw64/bin/g++.exe -fdiagnostics-color=always -g .\*.cpp -o .\main.exe -std=c++23 -I.\include -I.\Vulkan\include -L.\lib -L.\Vulkan\lib -lglfw3 -lvulkan-1 -lgdi32 && main.exe

조건

컴파일러가 mingw64로 설치되어 있으며,
아래 경로에 g++.exe가 있어야 함
C:/mingw64/bin/g++.exe

쉐이더 컴파일

C:/VulkanSDK/x.x.x.x/Bin/glslc.exe shader.vert -o vert.spv
C:/VulkanSDK/x.x.x.x/Bin/glslc.exe shader.frag -o frag.spv

filesystem::path rootPath = "F:/Vulkan/ThirdRectangle";
auto vertShaderCode = readFile((rootPath / "shaders/shader.vert.spv").string());
auto fragShaderCode = readFile((rootPath / "shaders/shader.frag.spv").string());
