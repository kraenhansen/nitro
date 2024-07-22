import type { Language } from '../../getPlatformSpecs.js'
import {
  getSourceFileImport,
  type SourceFile,
  type SourceImport,
} from '../SourceFile.js'
import type { Type, TypeKind } from './Type.js'

export class PromiseType implements Type {
  readonly resultingType: Type

  constructor(resultingType: Type) {
    this.resultingType = resultingType
  }

  get canBePassedByReference(): boolean {
    return false
  }
  get kind(): TypeKind {
    return 'promise'
  }

  getCode(language: Language): string {
    const resultingCode = this.resultingType.getCode(language)
    switch (language) {
      case 'c++':
        return `std::future<${resultingCode}>`
      case 'swift':
        // TODO: Implement Promise in Swift!
        return `Promise<${resultingCode}>`
      default:
        throw new Error(
          `Language ${language} is not yet supported for PromiseType!`
        )
    }
  }
  getExtraFiles(): SourceFile[] {
    return this.resultingType.getExtraFiles()
  }
  getRequiredImports(): SourceImport[] {
    return this.getExtraFiles().map((f) => getSourceFileImport(f))
  }
}