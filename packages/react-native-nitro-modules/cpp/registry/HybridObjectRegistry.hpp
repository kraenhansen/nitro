//
//  HybridObjectRegistry.hpp
//  DoubleConversion
//
//  Created by Marc Rousavy on 22.07.24.
//

#pragma once

#include "HybridObject.hpp"
#include <functional>
#include <string>

namespace margelo::nitro {

/**
 * A registry that holds initializers for HybridObjects.
 * This will be used to initialize them from JS using `NitroModules.create<T>(name)`.
 */
class HybridObjectRegistry {
public:
  HybridObjectRegistry() = delete;

public:
  using HybridObjectConstructorFn = std::function<std::shared_ptr<HybridObject>()>;

public:
  /**
   * Registers the given HybridObject in the `HybridObjectRegistry`.
   * It will be uniquely identified via it's `hybridObjectName`, and can be initialized from
   * JS using `NitroModules.create<T>(name)` - which will call the `constructorFn` here.
   */
  static void registerHybridObjectConstructor(const std::string& hybridObjectName, HybridObjectConstructorFn&& constructorFn);

  static std::shared_ptr<HybridObject> createHybridObject(const std::string& hybridObjectName);
  static bool hasHybridObject(const std::string& hybridObjectName);
  static std::vector<std::string> getAllHybridObjectNames();

private:
  static std::unordered_map<std::string, HybridObjectConstructorFn>& getRegistry();

private:
  static constexpr auto TAG = "HybridObjectRegistry";
};

} // namespace margelo::nitro
