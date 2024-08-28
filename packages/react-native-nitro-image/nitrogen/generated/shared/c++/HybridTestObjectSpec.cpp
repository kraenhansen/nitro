///
/// HybridTestObjectSpec.cpp
/// Wed Aug 28 2024
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

#include "HybridTestObjectSpec.hpp"

namespace margelo::nitro::image {

  void HybridTestObjectSpec::loadHybridMethods() {
    // load base methods/properties
    HybridObject::loadHybridMethods();
    // load custom methods/properties
    registerHybrids(this, [](Prototype& prototype) {
      prototype.registerHybridGetter("numberValue", &HybridTestObjectSpec::getNumberValue);
      prototype.registerHybridSetter("numberValue", &HybridTestObjectSpec::setNumberValue);
      prototype.registerHybridGetter("boolValue", &HybridTestObjectSpec::getBoolValue);
      prototype.registerHybridSetter("boolValue", &HybridTestObjectSpec::setBoolValue);
      prototype.registerHybridGetter("stringValue", &HybridTestObjectSpec::getStringValue);
      prototype.registerHybridSetter("stringValue", &HybridTestObjectSpec::setStringValue);
      prototype.registerHybridGetter("bigintValue", &HybridTestObjectSpec::getBigintValue);
      prototype.registerHybridSetter("bigintValue", &HybridTestObjectSpec::setBigintValue);
      prototype.registerHybridGetter("stringOrUndefined", &HybridTestObjectSpec::getStringOrUndefined);
      prototype.registerHybridSetter("stringOrUndefined", &HybridTestObjectSpec::setStringOrUndefined);
      prototype.registerHybridGetter("stringOrNull", &HybridTestObjectSpec::getStringOrNull);
      prototype.registerHybridSetter("stringOrNull", &HybridTestObjectSpec::setStringOrNull);
      prototype.registerHybridGetter("optionalString", &HybridTestObjectSpec::getOptionalString);
      prototype.registerHybridSetter("optionalString", &HybridTestObjectSpec::setOptionalString);
      prototype.registerHybridGetter("valueThatWillThrowOnAccess", &HybridTestObjectSpec::getValueThatWillThrowOnAccess);
      prototype.registerHybridSetter("valueThatWillThrowOnAccess", &HybridTestObjectSpec::setValueThatWillThrowOnAccess);
      prototype.registerHybridGetter("someVariant", &HybridTestObjectSpec::getSomeVariant);
      prototype.registerHybridSetter("someVariant", &HybridTestObjectSpec::setSomeVariant);
      prototype.registerHybridGetter("someTuple", &HybridTestObjectSpec::getSomeTuple);
      prototype.registerHybridSetter("someTuple", &HybridTestObjectSpec::setSomeTuple);
      prototype.registerHybridGetter("self", &HybridTestObjectSpec::getSelf);
      prototype.registerHybridMethod("simpleFunc", &HybridTestObjectSpec::simpleFunc);
      prototype.registerHybridMethod("addNumbers", &HybridTestObjectSpec::addNumbers);
      prototype.registerHybridMethod("addStrings", &HybridTestObjectSpec::addStrings);
      prototype.registerHybridMethod("multipleArguments", &HybridTestObjectSpec::multipleArguments);
      prototype.registerHybridMethod("createMap", &HybridTestObjectSpec::createMap);
      prototype.registerHybridMethod("mapRoundtrip", &HybridTestObjectSpec::mapRoundtrip);
      prototype.registerHybridMethod("funcThatThrows", &HybridTestObjectSpec::funcThatThrows);
      prototype.registerHybridMethod("tryOptionalParams", &HybridTestObjectSpec::tryOptionalParams);
      prototype.registerHybridMethod("tryMiddleParam", &HybridTestObjectSpec::tryMiddleParam);
      prototype.registerHybridMethod("passVariant", &HybridTestObjectSpec::passVariant);
      prototype.registerHybridMethod("getVariantEnum", &HybridTestObjectSpec::getVariantEnum);
      prototype.registerHybridMethod("getVariantObjects", &HybridTestObjectSpec::getVariantObjects);
      prototype.registerHybridMethod("getVariantHybrid", &HybridTestObjectSpec::getVariantHybrid);
      prototype.registerHybridMethod("getVariantTuple", &HybridTestObjectSpec::getVariantTuple);
      prototype.registerHybridMethod("flip", &HybridTestObjectSpec::flip);
      prototype.registerHybridMethod("passTuple", &HybridTestObjectSpec::passTuple);
      prototype.registerHybridMethod("calculateFibonacciSync", &HybridTestObjectSpec::calculateFibonacciSync);
      prototype.registerHybridMethod("calculateFibonacciAsync", &HybridTestObjectSpec::calculateFibonacciAsync);
      prototype.registerHybridMethod("wait", &HybridTestObjectSpec::wait);
      prototype.registerHybridMethod("callCallback", &HybridTestObjectSpec::callCallback);
      prototype.registerHybridMethod("getValueFromJSCallback", &HybridTestObjectSpec::getValueFromJSCallback);
      prototype.registerHybridMethod("getValueFromJSCallbackAndWait", &HybridTestObjectSpec::getValueFromJSCallbackAndWait);
      prototype.registerHybridMethod("callAll", &HybridTestObjectSpec::callAll);
      prototype.registerHybridMethod("getValueFromJsCallback", &HybridTestObjectSpec::getValueFromJsCallback);
      prototype.registerHybridMethod("getCar", &HybridTestObjectSpec::getCar);
      prototype.registerHybridMethod("isCarElectric", &HybridTestObjectSpec::isCarElectric);
      prototype.registerHybridMethod("getDriver", &HybridTestObjectSpec::getDriver);
      prototype.registerHybridMethod("createArrayBuffer", &HybridTestObjectSpec::createArrayBuffer);
      prototype.registerHybridMethod("getBufferLastItem", &HybridTestObjectSpec::getBufferLastItem);
      prototype.registerHybridMethod("setAllValuesTo", &HybridTestObjectSpec::setAllValuesTo);
      prototype.registerHybridMethod("newTestObject", &HybridTestObjectSpec::newTestObject);
    });
  }

} // namespace margelo::nitro::image
