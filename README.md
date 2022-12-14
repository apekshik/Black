
## Compiler Architecture
As a whole, the Black compiler is principally responsible for translating Black source code into efficient, executable machine code. However, the Black compiler front-end will also support a number of other tools, including IDE integration with syntax coloring, code completion, and other conveniences. This document provides a high-level description of the major components of the Black compiler:

- **Parsing:** The parser will be a recursive-descent parser (implemented in lib/Parse) with an integrated, hand-coded lexer. The parser is responsible for generating an Abstract Syntax Tree (AST) without any semantic or type information, and emit warnings or errors for grammatical problems with the input source.

- **Semantic analysis:** Semantic analysis (implemented in lib/Sema) will be responsible for taking the parsed AST and transforming it into a well-formed, - fully-type-checked form of the AST, emitting warnings or errors for semantic problems in the source code. Semantic analysis includes type inference and, on success, indicates that it is safe to generate code from the resulting, type-checked AST.

- **Clang importer:** The Clang importer (implemented in lib/ClangImporter) will import Clang modules and map the C or Objective-C APIs they export into their corresponding Black APIs. The resulting imported ASTs can be referred to by semantic analysis.

- **BIL generation:** The Black Intermediate Language (BIL) is a high-level, Black-specific intermediate language suitable for further analysis and optimization of Black code. The BIL generation phase (implemented in lib/BILGen) lowers the type-checked AST into so-called “raw” BIL. 

- **BIL guaranteed transformations:** The BIL guaranteed transformations (implemented in lib/BILOptimizer/Mandatory) perform additional dataflow diagnostics that affect the correctness of a program (such as a use of uninitialized variables). The end result of these transformations is “canonical” BIL.

- **BIL Optimizations:** The BIL optimizations (implemented in lib/Analysis, lib/ARC, lib/LoopTransforms, and lib/Transforms) perform additional high-level, Black-specific optimizations to the program.

- **LLVM IR Generation:** IR generation (implemented in lib/IRGen) lowers BIL to LLVM IR, at which point LLVM can continue to optimize it and generate machine code.
