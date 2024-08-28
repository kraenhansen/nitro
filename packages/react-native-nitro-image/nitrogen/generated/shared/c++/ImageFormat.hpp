///
/// ImageFormat.hpp
/// Wed Aug 28 2024
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

#pragma once

#if __has_include(<NitroModules/NitroHash.hpp>)
#include <NitroModules/NitroHash.hpp>
#else
#error NitroModules cannot be found! Are you sure you installed NitroModules properly?
#endif
#if __has_include(<NitroModules/JSIConverter.hpp>)
#include <NitroModules/JSIConverter.hpp>
#else
#error NitroModules cannot be found! Are you sure you installed NitroModules properly?
#endif
#if __has_include(<NitroModules/NitroDefines.hpp>)
#include <NitroModules/NitroDefines.hpp>
#else
#error NitroModules cannot be found! Are you sure you installed NitroModules properly?
#endif

namespace margelo::nitro::image {

  /**
   * An enum which can be represented as a JavaScript union (ImageFormat).
   */
  enum class ImageFormat {
    JPG      SWIFT_NAME(jpg) = 0,
    PNG      SWIFT_NAME(png) = 1,
  } CLOSED_ENUM;

} // namespace margelo::nitro::image

namespace margelo::nitro {

  using namespace margelo::nitro::image;

  // C++ ImageFormat <> JS ImageFormat (union)
  template <>
  struct JSIConverter<ImageFormat> {
    static inline ImageFormat fromJSI(jsi::Runtime& runtime, const jsi::Value& arg) {
      std::string unionValue = JSIConverter<std::string>::fromJSI(runtime, arg);
      switch (hashString(unionValue.c_str(), unionValue.size())) {
        case hashString("jpg"): return ImageFormat::JPG;
        case hashString("png"): return ImageFormat::PNG;
        default: [[unlikely]]
          throw std::runtime_error("Cannot convert \"" + unionValue + "\" to enum ImageFormat - invalid value!");
      }
    }
    static inline jsi::Value toJSI(jsi::Runtime& runtime, ImageFormat arg) {
      switch (arg) {
        case ImageFormat::JPG: return JSIConverter<std::string>::toJSI(runtime, "jpg");
        case ImageFormat::PNG: return JSIConverter<std::string>::toJSI(runtime, "png");
        default: [[unlikely]]
          throw std::runtime_error("Cannot convert ImageFormat to JS - invalid value: "
                                    + std::to_string(static_cast<int>(arg)) + "!");
      }
    }
    static inline bool canConvert(jsi::Runtime& runtime, const jsi::Value& value) {
      if (!value.isString()) {
        return false;
      }
      std::string unionValue = JSIConverter<std::string>::fromJSI(runtime, value);
      switch (hashString(unionValue.c_str(), unionValue.size())) {
        case hashString("jpg"):
        case hashString("png"):
          return true;
        default:
          return false;
      }
    }
  };

} // namespace margelo::nitro
