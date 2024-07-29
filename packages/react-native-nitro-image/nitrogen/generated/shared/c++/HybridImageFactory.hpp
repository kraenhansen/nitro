///
/// HybridImageFactory.hpp
/// Mon Jul 29 2024
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/react-native-nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

#pragma once

#if __has_include(<NitroModules/HybridObject.hpp>)
#include <NitroModules/HybridObject.hpp>
#elif __has_include("HybridObject.hpp")
#include "HybridObject.hpp"
#else
#error NitroModules cannot be found! Are you sure you installed NitroModules properly?
#endif

// Forward declaration of `HybridImage` to properly resolve imports.
namespace margelo::nitro::image { class HybridImage; }

#include "HybridImage.hpp"

namespace margelo::nitro::image {

  using namespace margelo::nitro;

  /**
   * An abstract base class for `ImageFactory`
   * Inherit this class to create instances of `HybridImageFactory` in C++.
   * @example
   * ```cpp
   * class ImageFactory: public HybridImageFactory {
   *   // ...
   * };
   * ```
   */
  class HybridImageFactory: public HybridObject {
    public:
      // Constructor
      explicit HybridImageFactory(): HybridObject(TAG) { }

      // Destructor
      ~HybridImageFactory() { }

    public:
      // Properties
      

    public:
      // Methods
      virtual std::shared_ptr<HybridImage> loadImageFromFile(const std::string& path) = 0;
      virtual std::shared_ptr<HybridImage> loadImageFromURL(const std::string& path) = 0;
      virtual std::shared_ptr<HybridImage> loadImageFromSystemName(const std::string& path) = 0;
      virtual std::shared_ptr<HybridImage> bounceBack(std::shared_ptr<HybridImage> image) = 0;

    protected:
      // Tag for logging
      static constexpr auto TAG = "ImageFactory";

    private:
      // Hybrid Setup
      void loadHybridMethods() override;
  };

} // namespace margelo::nitro::image