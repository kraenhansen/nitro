///
/// JHybridImageSpec.cpp
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

#include "JHybridImageSpec.hpp"
#include <NitroModules/JSIConverter+JNI.hpp>

namespace margelo::nitro::image {

  jni::local_ref<JHybridImageSpec::jhybriddata> JHybridImageSpec::initHybrid(jni::alias_ref<jhybridobject> jThis) {
    return makeCxxInstance(jThis);
  }

  void JHybridImageSpec::registerNatives() {
    registerHybrid({
      makeNativeMethod("initHybrid", JHybridImageSpec::initHybrid),
    });
  }

  size_t JHybridImageSpec::getExternalMemorySize() noexcept {
    static const auto method = _javaPart->getClass()->getMethod<jlong()>("getMemorySize");
    return method(_javaPart);
  }

  // Properties
  ImageSize JHybridImageSpec::getSize() {
    static const auto method = _javaPart->getClass()->getMethod<jni::alias_ref<JImageSize>()>("getSize");
    auto result = method(_javaPart);
    return result->toCpp();
  }
  PixelFormat JHybridImageSpec::getPixelFormat() {
    static const auto method = _javaPart->getClass()->getMethod<jni::alias_ref<JPixelFormat>()>("getPixelFormat");
    auto result = method(_javaPart);
    return result->toCpp();
  }
  double JHybridImageSpec::getSomeSettableProp() {
    static const auto method = _javaPart->getClass()->getMethod<double()>("getSomeSettableProp");
    auto result = method(_javaPart);
    return result;
  }
  void JHybridImageSpec::setSomeSettableProp(double someSettableProp) {
    static const auto method = _javaPart->getClass()->getMethod<void(double /* someSettableProp */)>("setSomeSettableProp");
    method(_javaPart, someSettableProp);
  }

  // Methods
  double JHybridImageSpec::toArrayBuffer(ImageFormat format) {
    static const auto method = _javaPart->getClass()->getMethod<double(jni::alias_ref<JImageFormat> /* format */)>("toArrayBuffer");
    auto result = method(_javaPart, JImageFormat::fromCpp(format));
    return result;
  }
  void JHybridImageSpec::saveToFile(const std::string& path, const std::function<void(const std::string& /* path */)>& onFinished) {
    static const auto method = _javaPart->getClass()->getMethod<void(jni::alias_ref<jni::JString> /* path */, jni::alias_ref<JFunc_void_std__string::javaobject> /* onFinished */)>("saveToFile");
    method(_javaPart, jni::make_jstring(path), JFunc_void_std__string::fromCpp(onFinished));
  }

  void JHybridImageSpec::loadHybridMethods() {
    // Load base Prototype methods
    HybridImageSpec::loadHybridMethods();
    // Override base Prototype methods with JNI methods
    registerHybrids(this, [](Prototype& prototype) {
      prototype.registerHybridGetter("size", &JHybridImageSpec::getSizeJNI);
      prototype.registerHybridGetter("pixelFormat", &JHybridImageSpec::getPixelFormatJNI);
      prototype.registerHybridGetter("someSettableProp", &JHybridImageSpec::getSomeSettablePropJNI);
      prototype.registerHybridSetter("someSettableProp", &JHybridImageSpec::setSomeSettablePropJNI);
      prototype.registerHybridMethod("toArrayBuffer", &JHybridImageSpec::toArrayBufferJNI);
      prototype.registerHybridMethod("saveToFile", &JHybridImageSpec::saveToFileJNI);
    });
  }

} // namespace margelo::nitro::image
