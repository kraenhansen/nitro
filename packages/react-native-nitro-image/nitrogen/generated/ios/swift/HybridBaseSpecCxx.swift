///
/// HybridBaseSpecCxx.swift
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

import Foundation
import NitroModules

/**
 * A concrete class/struct implementation that bridges HybridBaseSpec over to C++.
 * In C++, we cannot use Swift protocols - so we need to wrap it in a class/struct to make it strongly defined.
 *
 * Also, some Swift types need to be bridged with special handling:
 * - Enums need to be wrapped in Structs, otherwise they cannot be accessed bi-directionally (Swift bug: https://github.com/swiftlang/swift/issues/75330)
 * - Other HybridObjects need to be wrapped/unwrapped from the Swift TCxx wrapper
 * - Throwing methods need to be wrapped with a Result<T, Error> type, as exceptions cannot be propagated to C++
 */
public struct HybridBaseSpecCxx {
  /**
   * The Swift <> C++ bridge's namespace (`margelo::nitro::image::bridge::swift`)
   * from `NitroImage-Swift-Cxx-Bridge.hpp`.
   * This contains specialized C++ templates, and C++ helper functions that can be accessed from Swift.
   */
  public typealias bridge = margelo.nitro.image.bridge.swift

  /**
   * Holds an instance of the `HybridBaseSpec` Swift protocol.
   */
  private var implementation: HybridBaseSpec

  /**
   * Get the actual `HybridBaseSpec` instance this class wraps.
   */
  @inline(__always)
  public func getHybridBaseSpec() -> HybridBaseSpec {
    return implementation
  }

  /**
   * Create a new `HybridBaseSpecCxx` that wraps the given `HybridBaseSpec`.
   * All properties and methods bridge to C++ types.
   */
  public init(_ implementation: HybridBaseSpec) {
    self.implementation = implementation
    
  }

  /**
   * Contains a (weak) reference to the C++ HybridObject to cache it.
   */
  public var hybridContext: margelo.nitro.HybridContext {
    get {
      return self.implementation.hybridContext
    }
    set {
      self.implementation.hybridContext = newValue
    }
  }

  /**
   * Get the memory size of the Swift class (plus size of any other allocations)
   * so the JS VM can properly track it and garbage-collect the JS object if needed.
   */
  public var memorySize: Int {
    return self.implementation.memorySize
  }

  // Properties
  public var baseValue: Double {
    @inline(__always)
    get {
      return self.implementation.baseValue
    }
  }

  // Methods
  
}
