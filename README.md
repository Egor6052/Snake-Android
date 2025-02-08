This is a simple snake game.

![Logo](assets/logo.png "Snake!") 

Переконайся, що Android SDK і NDK встановлені. 
Налаштуй змінні середовища:
```
export ANDROID_SDK_ROOT=~/Android/Sdk
export ANDROID_NDK_HOME=$ANDROID_SDK_ROOT/ndk/25.1.8937393 # Вкажи свою версію NDK
export PATH=$ANDROID_SDK_ROOT/cmake/3.22.1/bin:$PATH
```
Збери .so бібліотеку:
```
mkdir -p build && cd build
cmake .. -G Ninja \
    -DCMAKE_TOOLCHAIN_FILE=$ANDROID_NDK_HOME/build/cmake/android.toolchain.cmake \
    -DANDROID_ABI=arm64-v8a \
    -DANDROID_PLATFORM=android-21 \
    -DCMAKE_BUILD_TYPE=Release
cmake --build .
```
Створення .apk:
```
cd android
./gradlew assembleDebug
```

_Запуск на пристрої або емуляторі_
```
_adb install -r app/build/outputs/apk/debug/app-debug.apk_
```