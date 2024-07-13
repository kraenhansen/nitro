///
/// Car.hpp
/// Sat Jul 13 2024
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/react-native-nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///


#pragma once

#include <stddef.h>
#include <string.h>
#include <optional>
#include <NitroModules/JSIConverter.hpp>

#include "Battery.hpp"
#include "Powertrain.hpp"

struct Car {
public:
  std::string make;
  std::string model;
  std::optional<Battery> battery;
  Powertrain powertrain;
  double price;
};

namespace margelo {

  // C++ Car <> JS Car
  template <> struct JSIConverter<Car> {
    static Car fromJSI(jsi::Runtime& runtime, const jsi::Value& arg) {
      jsi::Object obj = arg.asObject(runtime);
      return Car {
        .make = JSIConverter<std::string>::fromJSI(runtime, obj.getProperty(runtime, "make")),
        .model = JSIConverter<std::string>::fromJSI(runtime, obj.getProperty(runtime, "model")),
        .battery = JSIConverter<std::optional<Battery>>::fromJSI(runtime, obj.getProperty(runtime, "battery")),
        .powertrain = JSIConverter<Powertrain>::fromJSI(runtime, obj.getProperty(runtime, "powertrain")),
        .price = JSIConverter<double>::fromJSI(runtime, obj.getProperty(runtime, "price")),
      };
    }
    static jsi::Value toJSI(jsi::Runtime& runtime, const Car& arg) {
      jsi::Object obj(runtime);
      obj.setProperty(runtime, "make", JSIConverter<std::string>::toJSI(runtime, arg.make));
      obj.setProperty(runtime, "model", JSIConverter<std::string>::toJSI(runtime, arg.model));
      obj.setProperty(runtime, "battery", JSIConverter<std::optional<Battery>>::toJSI(runtime, arg.battery));
      obj.setProperty(runtime, "powertrain", JSIConverter<Powertrain>::toJSI(runtime, arg.powertrain));
      obj.setProperty(runtime, "price", JSIConverter<double>::toJSI(runtime, arg.price));
      return obj;
    }
  };

} // namespace margelo