/*
 * Copyright (c) 2011, Andrew Sorensen
 *
 * All rights reserved.
 *
 *
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, 
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation 
 *    and/or other materials provided with the distribution.
 *
 * Neither the name of the authors nor other contributors may be used to endorse
 * or promote products derived from this software without specific prior written 
 * permission.
 *
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
 * ARE DISCLEXTD. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE 
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef _SCHEME_FFI_H
#define _SCHEME_FFI_H

#include "Scheme.h"
#include "EXTLLVM.h"
#include "Task.h";

namespace extemp {

	class SchemeFFI {
	public:
		SchemeFFI() {};
		~SchemeFFI() {};
		static SchemeFFI* I() { return &SINGLETON; }
		
		// helper functions
		void initSchemeFFI(scheme* _sc);		
		void addGlobal(scheme* sc, char* symbol_name, pointer arg);
		void addForeignFunc(scheme* sc, char* symbol_name, foreign_func func);
		void addGlobalCptr(scheme* sc, char* symbol_name, void* ptr);		
		
		// misc stuff
		static pointer pointerSize(scheme* _sc, pointer args);
		static pointer stringStrip(scheme* _sc, pointer args);
		static pointer stringJoin(scheme* _sc, pointer args);
		static pointer getClosureEnv(scheme* _sc, pointer args);
		static pointer getTime(scheme* _sc, pointer args);
		static pointer sexprToString(scheme* _sc, pointer args);
		static pointer print(scheme* _sc, pointer args);
		static pointer printFull(scheme* _sc, pointer args);
		static pointer printFullNoQuotes(scheme* _sc, pointer args);
		static pointer printError(scheme* _sc, pointer args);
		static pointer printNotification(scheme* _sc, pointer args);
		static pointer callCPPAtTime(scheme* _sc, pointer args);
		
		// regex stuff
		static pointer regex_match(scheme* _sc, pointer args);
		static pointer regex_matched(scheme* _sc, pointer args);
		static pointer regex_match_all(scheme* _sc, pointer args);
		static pointer regex_split(scheme* _sc, pointer args);
		static pointer regex_replace(scheme* _sc, pointer args);
		
		// memory zone stuff
		void destroyMallocZoneWithDelay(TaskI* task);
		static pointer createMallocZone(scheme* _sc, pointer args);
		static pointer defaultMallocZone(scheme* _sc, pointer args);
		static pointer destroyMallocZone(scheme* _sc, pointer args);
		static pointer copyToDefaultZone(scheme* _sc, pointer args);
			
		// llvm stuff
		static pointer compile(scheme* _sc, pointer args);
		static pointer bind_global_var(scheme* _sc, pointer args);		
		static pointer get_function(scheme* _sc, pointer args);
		static pointer get_globalvar(scheme* _sc, pointer args);		
		static pointer get_function_args(scheme* _sc, pointer args);		
		static pointer get_function_type(scheme* _sc, pointer args);		
		static pointer get_function_calling_conv(scheme* _sc, pointer args);		
		static pointer get_global_variable_type(scheme* _sc, pointer args);		
		static pointer get_function_pointer(scheme* _sc, pointer args);		
		static pointer recompile_and_link_function(scheme* _sc, pointer args);		
		static pointer remove_function(scheme* _sc, pointer args);		
		static pointer remove_global_var(scheme* _sc, pointer args);		
		static pointer erase_function(scheme* _sc, pointer args);
		static pointer call_compiled(scheme* _sc, pointer args);
		static pointer call_compiled_closure(scheme* _sc, pointer args);
		static pointer llvm_convert_float_constant(scheme* _sc, pointer args);
		static pointer llvm_count(scheme* _sc, pointer args);
		static pointer llvm_count_inc(scheme* _sc, pointer args);
		static pointer callClosure(scheme* _sc, pointer args);
		static pointer printLLVMModule(scheme* _sc, pointer args);
		static pointer printLLVMFunction(scheme* _sc, pointer args);
		
		// dsp bits
		static pointer setDSPClosure(scheme* _sc, pointer args);
		static pointer setDSPWrapper(scheme* _sc, pointer args);
		static pointer setDSPWrapperArray(scheme* _sc, pointer args);
		
	private:
		static SchemeFFI SINGLETON;		
	};
	
} // end namespace

#endif