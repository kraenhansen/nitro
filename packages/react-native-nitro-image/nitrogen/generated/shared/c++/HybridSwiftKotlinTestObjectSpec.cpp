///
/// HybridSwiftKotlinTestObjectSpec.cpp
/// Tue Aug 13 2024
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/react-native-nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

#include "HybridSwiftKotlinTestObjectSpec.hpp"

namespace margelo::nitro::image {

  void HybridSwiftKotlinTestObjectSpec::loadHybridMethods() {
    // load base methods/properties
    HybridObject::loadHybridMethods();
    // load custom methods/properties
    registerHybrids(this, [](Prototype& prototype) {
      prototype.registerHybridGetter("numberValue", &HybridSwiftKotlinTestObjectSpec::getNumberValue);
      prototype.registerHybridSetter("numberValue", &HybridSwiftKotlinTestObjectSpec::setNumberValue);
      prototype.registerHybridGetter("boolValue", &HybridSwiftKotlinTestObjectSpec::getBoolValue);
      prototype.registerHybridSetter("boolValue", &HybridSwiftKotlinTestObjectSpec::setBoolValue);
      prototype.registerHybridGetter("stringValue", &HybridSwiftKotlinTestObjectSpec::getStringValue);
      prototype.registerHybridSetter("stringValue", &HybridSwiftKotlinTestObjectSpec::setStringValue);
      prototype.registerHybridGetter("bigintValue", &HybridSwiftKotlinTestObjectSpec::getBigintValue);
      prototype.registerHybridSetter("bigintValue", &HybridSwiftKotlinTestObjectSpec::setBigintValue);
      prototype.registerHybridGetter("stringOrUndefined", &HybridSwiftKotlinTestObjectSpec::getStringOrUndefined);
      prototype.registerHybridSetter("stringOrUndefined", &HybridSwiftKotlinTestObjectSpec::setStringOrUndefined);
      prototype.registerHybridGetter("stringOrNull", &HybridSwiftKotlinTestObjectSpec::getStringOrNull);
      prototype.registerHybridSetter("stringOrNull", &HybridSwiftKotlinTestObjectSpec::setStringOrNull);
      prototype.registerHybridGetter("optionalString", &HybridSwiftKotlinTestObjectSpec::getOptionalString);
      prototype.registerHybridSetter("optionalString", &HybridSwiftKotlinTestObjectSpec::setOptionalString);
      prototype.registerHybridMethod("simpleFunc", &HybridSwiftKotlinTestObjectSpec::simpleFunc);
      prototype.registerHybridMethod("addNumbers", &HybridSwiftKotlinTestObjectSpec::addNumbers);
      prototype.registerHybridMethod("addStrings", &HybridSwiftKotlinTestObjectSpec::addStrings);
      prototype.registerHybridMethod("multipleArguments", &HybridSwiftKotlinTestObjectSpec::multipleArguments);
    });
  }

} // namespace margelo::nitro::image
