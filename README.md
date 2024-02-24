실행 코드 (릴리즈 빌드), (디버그 빌드는 -mwindows 옵션을 빼면 됨)

g++ -fdiagnostics-color=always -g .\*.cpp .\BaseClass\*.cpp .\CustomVK\*.cpp FileInfo.res -o .\main.exe -std=c++23 -I.\include -I.\Vulkan\include -L.\lib -L.\Vulkan\lib -mwindows -lglfw3 -lvulkan-1 -lgdi32 && main.exe

조건

컴파일러가 mingw64(mingw64-posix-seh-msvcrt)로 설치되어 있으며,
콘솔에 g++ 명령이 동작하도록 세팅 해야 함 (권장 버전은 g++-13 이상)

쉐이더 컴파일

C:/VulkanSDK/x.x.x.x/Bin/glslc.exe shader.vert -o vert.spv
C:/VulkanSDK/x.x.x.x/Bin/glslc.exe shader.frag -o frag.spv

실행파일의 정보파일 컴파일

windres FileInfo.rc -O coff -o FileInfo.res
