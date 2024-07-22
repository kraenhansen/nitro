import type { Language } from '../../getPlatformSpecs.js'
import {
  getSourceFileImport,
  type SourceFile,
  type SourceImport,
} from '../SourceFile.js'
import type { Type, TypeKind } from './Type.js'

export class OptionalType implements Type {
  readonly wrappingType: Type

  constructor(wrappingType: Type) {
    this.wrappingType = wrappingType
  }

  get canBePassedByReference(): boolean {
    return true
  }
  get kind(): TypeKind {
    return 'optional'
  }

  getCode(language: Language): string {
    const wrapping = this.wrappingType.getCode(language)
    switch (language) {
      case 'c++':
        return `std::optional<${wrapping}>`
      case 'swift':
        return `${wrapping}?`
      default:
        throw new Error(
          `Language ${language} is not yet supported for OptionalType!`
        )
    }
  }
  getExtraFiles(): SourceFile[] {
    return this.wrappingType.getExtraFiles()
  }
  getRequiredImports(): SourceImport[] {
    return this.getExtraFiles().map((f) => getSourceFileImport(f))
  }
}