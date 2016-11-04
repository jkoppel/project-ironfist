/*
 * Copyright 2011 James Koppel
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file excfept in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * Referee creates struct xrefs for decompiled functions
 */


#include <hexrays.hpp>
#include <loader.hpp>
#include <typeinf.hpp>
#include <struct.hpp>

// Hex-Rays API pointer
hexdsp_t *hexdsp = NULL;

static bool inited = false;

bool is_assn(ctype_t t) {
	return
		t == cot_asg ||
		t == cot_asgbor ||
		t == cot_asgxor ||
		t == cot_asgband ||
		t == cot_asgsub ||
		t == cot_asgmul ||
		t == cot_asgsshr ||
		t == cot_asgushr ||
		t == cot_asgsdiv ||
		t == cot_asgudiv ||
		t == cot_asgsmod ||
		t == cot_asgumod;
}

void add_struct_xrefs(cfunc_t* cfunc) {
	struct xref_adder_t : public ctree_visitor_t {
		ea_t fn_ea;
		xref_adder_t(ea_t ea) : ctree_visitor_t(CV_FAST) {
			fn_ea = ea;
		}

		int idaapi visit_expr(cexpr_t *e) {
			uint32 dr = dr_R | XREF_USER;

			//We wish to know what context a struct usage occurs in
			//so we can determine what kind of xref to create. Unfortunately,
			//a post-order traversal makes this difficult.

			//For assignments, we visit the left, instead
			//Note that immediate lvalues will be visited twice,
			//and will be eronneously marked with a read dref.
			//However, it is safer to overapproximate than underapproximate
			if(is_assn(e->op)) {
				e = e->x;
				dr = dr_W | XREF_USER;
			}

			//We do something similar for references
			if(e->op == cot_ref) {
				e = e->x;
				dr = dr_O | XREF_USER;
			}

			if(e->op == cot_memref || e->op == cot_memptr) {
				uint32 moff = e->m;


				/*
				 * The only way I could figure out how
				 * to get the structure/member associated with its use
				 */

				typestring typ = e->x->type;

				if(e->op == cot_memptr)
					typ.remove_ptr_or_array();

				char buf[MAXSTR];
				typ.print(buf, sizeof(buf));
				
				char* strname = buf;
				
				if(strstr(strname, "struct ") == strname)
					strname += sizeof("struct ") - 1;

				tid_t stid = get_struc_id(strname);
				struc_t* s = get_struc(stid);
				member_t* mem = get_member(s, moff);

				if(s != NULL) {

					add_dref(fn_ea, stid, (dref_t)(dr_R | XREF_USER)); 
					if(mem != NULL)
						add_dref(fn_ea, mem->id, (dref_t)dr);
				} else {
					msg("Referee failure in %a on struct %s (id: %d)\n", fn_ea, strname, stid);
				}
			}

			return 0;
		}
	};
	xref_adder_t adder(cfunc->entry_ea);
	adder.apply_to_exprs(&cfunc->body, NULL);
}

void clear_struct_xrefs(cfunc_t *cfunc) {
	xrefblk_t xb;
	for ( bool ok=xb.first_from(cfunc->entry_ea, XREF_DATA); ok; ok=xb.next_from() ) {
		if(xb.user == 1) {
			del_dref(cfunc->entry_ea, xb.to);
		}
    }
}

static int idaapi callback(void*, hexrays_event_t event, va_list va) {
	switch(event) {
	case hxe_maturity:
		cfunc_t* cfunc = va_arg(va, cfunc_t*);
		ctree_maturity_t mat = va_argi(va, ctree_maturity_t);

		if(mat == CMAT_FINAL) {
			//msg("Referee analyzing function at %a\n", cfunc->entry_ea);
			clear_struct_xrefs(cfunc);
			add_struct_xrefs(cfunc);
		}
	}
	return 0;
}

//--------------------------------------------------------------------------
void idaapi run(int /*arg*/)
{
	//never called
}

//--------------------------------------------------------------------------
int idaapi init(void)
{
	if(!init_hexrays_plugin())
		return PLUGIN_SKIP;

	install_hexrays_callback(callback, NULL);
	const char* hexver = get_hexrays_version();
	msg("Hex-Rays version %s has been detected; %s is ready to use\n", hexver, PLUGIN.wanted_name);
	inited = true;

	return PLUGIN_KEEP;
}

//--------------------------------------------------------------------------
void idaapi term(void)
{
	if(inited) {
		remove_hexrays_callback(callback, NULL);
		term_hexrays_plugin();
	}
}

//--------------------------------------------------------------------------
char wanted_name[] = "Referee";
char wanted_hotkey[] = "";
static char comment[] = "Adds struct xref info from decompilation";

//--------------------------------------------------------------------------
//
//      PLUGIN DESCRIPTION BLOCK
//
//--------------------------------------------------------------------------
plugin_t PLUGIN =
{
  IDP_INTERFACE_VERSION,
  PLUGIN_HIDE, // plugin flags
  init,                 // initialize

  term,                 // terminate. this pointer may be NULL.

  run,                  // invoke plugin

  comment,          // long comment about the plugin
                        // it could appear in the status line
                        // or as a hint

  wanted_name,          // multiline help about the plugin

  wanted_name,          // the preferred short name of the plugin
  wanted_hotkey         // the preferred hotkey to run the plugin
};
