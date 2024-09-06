///
/// CallbackHolder.swift
/// Fri Sep 06 2024
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

import NitroModules

/**
 * Represents an instance of `CallbackHolder`, backed by a C++ struct.
 */
public typealias CallbackHolder = margelo.nitro.image.CallbackHolder

public extension CallbackHolder {
  private typealias bridge = margelo.nitro.image.bridge.swift

  /**
   * Create a new instance of `CallbackHolder`.
   */
  init(callback: @escaping (() -> Void)) {
    self.init({ () -> bridge.Func_void.TFunc in
      class ClosureHolder {
        let closure: (() -> Void)
        init(wrappingClosure closure: @escaping (() -> Void)) {
          self.closure = closure
        }
        func invoke() {
          self.closure()
        }
      }
    
      let closureHolder = Unmanaged.passRetained(ClosureHolder(wrappingClosure: callback)).toOpaque()
      func callClosure(closureHolder: UnsafeMutableRawPointer?) -> Void {
        let closure = Unmanaged<ClosureHolder>.fromOpaque(closureHolder!).takeUnretainedValue()
        closure.invoke()
      }
      func destroyClosure(_ closureHolder: UnsafeMutableRawPointer?) -> Void {
        Unmanaged<ClosureHolder>.fromOpaque(closureHolder!).release()
      }
    
      let funcWrapper = bridge.create_Func_void(closureHolder, callClosure, destroyClosure)
      return funcWrapper.function
    }())
  }

  var callback: (() -> Void) {
    @inline(__always)
    get {
      return { () -> (() -> Void) in
        return { () -> Void in
          self.__callback()
        }
      }()
    }
    @inline(__always)
    set {
      self.__callback = { () -> bridge.Func_void.TFunc in
        class ClosureHolder {
          let closure: (() -> Void)
          init(wrappingClosure closure: @escaping (() -> Void)) {
            self.closure = closure
          }
          func invoke() {
            self.closure()
          }
        }
      
        let closureHolder = Unmanaged.passRetained(ClosureHolder(wrappingClosure: newValue)).toOpaque()
        func callClosure(closureHolder: UnsafeMutableRawPointer?) -> Void {
          let closure = Unmanaged<ClosureHolder>.fromOpaque(closureHolder!).takeUnretainedValue()
          closure.invoke()
        }
        func destroyClosure(_ closureHolder: UnsafeMutableRawPointer?) -> Void {
          Unmanaged<ClosureHolder>.fromOpaque(closureHolder!).release()
        }
      
        let funcWrapper = bridge.create_Func_void(closureHolder, callClosure, destroyClosure)
        return funcWrapper.function
      }()
    }
  }
}
