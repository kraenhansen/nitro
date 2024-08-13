import { escapeCppName } from '../helpers.js'
import type { SourceImport } from '../SourceFile.js'
import { ArrayType } from '../types/ArrayType.js'
import { FunctionType } from '../types/FunctionType.js'
import { getTypeAs } from '../types/getTypeAs.js'
import { OptionalType } from '../types/OptionalType.js'
import { RecordType } from '../types/RecordType.js'
import type { Type } from '../types/Type.js'

export interface SwiftCxxHelper {
  cxxCode: string
  funcName: string
  requiredIncludes: SourceImport[]
}

export function createSwiftCxxHelpers(type: Type): SwiftCxxHelper[] {
  switch (type.kind) {
    case 'optional':
      return createCxxOptionalSwiftHelper(getTypeAs(type, OptionalType))
    case 'array':
      return createCxxVectorSwiftHelper(getTypeAs(type, ArrayType))
    case 'record':
      return createCxxUnorderedMapSwiftHelper(getTypeAs(type, RecordType))
    case 'function':
      return createCxxFunctionSwiftHelper(getTypeAs(type, FunctionType))
    default:
      return []
  }
}

/**
 * Creates a C++ `create_optional<T>(value)` function that can be called from Swift.
 */
export function createCxxOptionalSwiftHelper(
  type: OptionalType
): SwiftCxxHelper[] {
  const actualType = type.getCode('c++')
  const name = escapeCppName(type.getCode('c++'))
  return [
    {
      funcName: `create_${name}`,
      requiredIncludes: [
        {
          name: 'optional',
          space: 'system',
          language: 'c++',
        },
        ...type.getRequiredImports(),
      ],
      cxxCode: `
using ${name} = ${actualType};
inline ${actualType} create_${name}(const ${type.wrappingType.getCode('c++')}& value) {
  return ${actualType}(value);
}
    `.trim(),
    },
  ]
}

/**
 * Creates a C++ `create_vector_T<T>(size)` function that can be called from Swift.
 */
export function createCxxVectorSwiftHelper(type: ArrayType): SwiftCxxHelper[] {
  const actualType = type.getCode('c++')
  const name = escapeCppName(type.getCode('c++'))
  return [
    {
      funcName: `create_${name}`,
      requiredIncludes: [
        {
          name: 'vector',
          space: 'system',
          language: 'c++',
        },
        ...type.getRequiredImports(),
      ],
      cxxCode: `
using ${name} = ${actualType};
inline ${actualType} create_${name}(size_t size) {
  ${actualType} vector;
  vector.reserve(size);
  return vector;
}
    `.trim(),
    },
  ]
}

/**
 * Creates a C++ `makeUnorderedMap<T>(size)` function that can be called from Swift.
 */
export function createCxxUnorderedMapSwiftHelper(
  type: RecordType
): SwiftCxxHelper[] {
  const actualType = type.getCode('c++')
  const name = escapeCppName(type.getCode('c++'))
  return [
    {
      funcName: `create_${name}`,
      requiredIncludes: [
        {
          name: 'unordered_map',
          space: 'system',
          language: 'c++',
        },
        ...type.getRequiredImports(),
      ],
      cxxCode: `
using ${name} = ${actualType};
inline ${actualType} create_${name}(size_t size) {
  ${actualType} map;
  map.reserve(size);
  return map;
}
    `.trim(),
    },
  ]
}

/**
 * Creates a C++ `Func_XXXXX` specialization that can be used from Swift.
 */
export function createCxxFunctionSwiftHelper(
  type: FunctionType
): SwiftCxxHelper[] {
  const name = type.specializationName
  return [
    {
      funcName: `create_${name}`,
      requiredIncludes: [
        {
          name: 'functional',
          space: 'system',
          language: 'c++',
        },
        ...type.getRequiredImports(),
      ],
      cxxCode: `
using ${name} = ${type.getCode('c++', false)};
    `.trim(),
    },
  ]
}