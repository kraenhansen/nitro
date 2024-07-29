import type { Language } from '../../getPlatformSpecs.js'
import { getAndroidPackage, getCxxNamespace } from '../../options.js'
import { createCppStruct } from '../c++/CppStruct.js'
import { getForwardDeclaration } from '../c++/getForwardDeclaration.js'
import {
  type FileWithReferencedTypes,
  type SourceFile,
  type SourceImport,
} from '../SourceFile.js'
import type { NamedType, Type, TypeKind } from './Type.js'

export class StructType implements Type {
  readonly structName: string
  readonly properties: NamedType[]
  readonly declarationFile: FileWithReferencedTypes

  constructor(structName: string, properties: NamedType[]) {
    this.structName = structName
    this.properties = properties
    this.declarationFile = createCppStruct(structName, properties)
  }

  get canBePassedByReference(): boolean {
    return true
  }
  get kind(): TypeKind {
    return 'struct'
  }

  getCode(language: Language): string {
    switch (language) {
      case 'c++':
        return this.structName
      case 'swift':
        return getCxxNamespace('swift', this.structName)
      case 'kotlin':
        return getAndroidPackage('java/kotlin', this.structName)
      default:
        throw new Error(
          `Language ${language} is not yet supported for StructType!`
        )
    }
  }
  getExtraFiles(): SourceFile[] {
    return [this.declarationFile]
  }
  getRequiredImports(): SourceImport[] {
    const cxxNamespace = getCxxNamespace('c++')
    const extraImport: SourceImport = {
      name: this.declarationFile.name,
      language: this.declarationFile.language,
      forwardDeclaration: getForwardDeclaration(
        'struct',
        this.structName,
        cxxNamespace
      ),
    }
    return [extraImport]
  }
}
