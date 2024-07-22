import {
  createFileMetadataString,
  escapeCppName,
  isNotDuplicate,
} from '../helpers.js'
import type { SourceFile } from '../SourceFile.js'
import type { FunctionType } from '../types/FunctionType.js'

export interface FunctionSpecialization {
  typename: string
  declarationFile: SourceFile
}

export function createCppFunctionSpecialization(
  func: FunctionType
): FunctionSpecialization {
  const returnType = func.returnType.getCode('c++')
  const paramsEscaped = func.parameters
    .map((p) => escapeCppName(p.getCode('c++')))
    .join('_')
  let typename = `Func_${escapeCppName(returnType)}`
  if (paramsEscaped.length > 0) {
    typename += `_${paramsEscaped}`
  }

  const extraImports = [
    ...func.returnType.getRequiredImports(),
    ...func.parameters.flatMap((p) => p.getRequiredImports()),
  ]
  const extraIncludes = extraImports
    .map((i) => `#include "${i.name}"`)
    .join('\n')
  const extraForwardDeclarations = extraImports
    .map((i) => i.forwardDeclaration)
    .filter((i) => i != null)
    .filter(isNotDuplicate)
    .join('\n')

  const paramsJs = func.parameters
    .map((p) => `${p.name}: ${p.getCode('c++')}`)
    .join(', ')
  const paramsCpp = func.parameters
    .map((p) => `${p.getCode('c++')} /* ${p.name} */`)
    .join(', ')

  const code = `
${createFileMetadataString(typename)}

#include <functional>
#include <string>

${extraForwardDeclarations}

${extraIncludes}

/**
 * A \`(${paramsJs}) => ${returnType}\` function.
 */
using ${typename} = std::function<${returnType}(${paramsCpp})>;
  `

  return {
    typename: typename,
    declarationFile: {
      content: code.trim(),
      language: 'c++',
      name: `${typename}.hpp`,
      platform: 'shared',
    },
  }
}