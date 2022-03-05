# imgui starter

## install

**vcpkg cmake**

```sh
brew install vcpkg cmake
git clone https://github.com/microsoft/vcpkg "$HOME/vcpkg"
export VCPKG_ROOT="$HOME/vcpkg"
vcpkg install imgui[core,glfw-binding,opengl3-binding] --recurse
```

**vscode settings**

```json
"cmake.configureSettings": {
  "CMAKE_TOOLCHAIN_FILE": "[vcpkg root]/scripts/buildsystems/vcpkg.cmake"
}
```
