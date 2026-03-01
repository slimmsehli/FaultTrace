// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_top.h for the primary calling header

#include "Vtb_top__pch.h"
#include "Vtb_top__Syms.h"
#include "Vtb_top___024root.h"

extern const VlWide<8>/*255:0*/ Vtb_top__ConstPool__CONST_h2409fbff_0;
extern const VlWide<8>/*255:0*/ Vtb_top__ConstPool__CONST_h5130200a_0;
extern const VlWide<8>/*255:0*/ Vtb_top__ConstPool__CONST_h20ae5363_0;
extern const VlWide<8>/*255:0*/ Vtb_top__ConstPool__CONST_ha0ca69a4_0;
extern const VlWide<8>/*255:0*/ Vtb_top__ConstPool__CONST_hd636e1b5_0;
extern const VlWide<8>/*255:0*/ Vtb_top__ConstPool__CONST_h5972b5a4_0;
extern const VlWide<8>/*255:0*/ Vtb_top__ConstPool__CONST_ha0f9cb69_0;
extern const VlWide<8>/*255:0*/ Vtb_top__ConstPool__CONST_hbb9be1b4_0;
extern const VlWide<8>/*255:0*/ Vtb_top__ConstPool__CONST_h11665c5b_0;
extern const VlWide<8>/*255:0*/ Vtb_top__ConstPool__CONST_hff5f4d65_0;
extern const VlWide<8>/*255:0*/ Vtb_top__ConstPool__CONST_h64d54945_0;

VL_INLINE_OPT VlCoroutine Vtb_top___024root___eval_initial__TOP__Vtiming__0(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___eval_initial__TOP__Vtiming__0\n"); );
    // Init
    VlWide<8>/*255:0*/ __Vtask_tb_top__DOT__separator__0__name;
    VL_ZERO_W(256, __Vtask_tb_top__DOT__separator__0__name);
    IData/*31:0*/ __Vtask_tb_top__DOT__cpu_read__1__core;
    __Vtask_tb_top__DOT__cpu_read__1__core = 0;
    CData/*7:0*/ __Vtask_tb_top__DOT__cpu_read__1__addr;
    __Vtask_tb_top__DOT__cpu_read__1__addr = 0;
    IData/*31:0*/ __Vtask_tb_top__DOT__cpu_read__1__rdata;
    __Vtask_tb_top__DOT__cpu_read__1__rdata = 0;
    IData/*31:0*/ __Vtask_tb_top__DOT__check_data__2__actual;
    __Vtask_tb_top__DOT__check_data__2__actual = 0;
    IData/*31:0*/ __Vtask_tb_top__DOT__check_data__2__expected;
    __Vtask_tb_top__DOT__check_data__2__expected = 0;
    VlWide<4>/*127:0*/ __Vtask_tb_top__DOT__check_data__2__label;
    VL_ZERO_W(128, __Vtask_tb_top__DOT__check_data__2__label);
    IData/*31:0*/ __Vtask_tb_top__DOT__check_mesi__3__cache;
    __Vtask_tb_top__DOT__check_mesi__3__cache = 0;
    CData/*2:0*/ __Vtask_tb_top__DOT__check_mesi__3__index;
    __Vtask_tb_top__DOT__check_mesi__3__index = 0;
    CData/*1:0*/ __Vtask_tb_top__DOT__check_mesi__3__expected;
    __Vtask_tb_top__DOT__check_mesi__3__expected = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__addr_to_index__4__Vfuncout;
    __Vfunc_tb_top__DOT__addr_to_index__4__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__addr_to_index__4__a;
    __Vfunc_tb_top__DOT__addr_to_index__4__a = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_top__DOT__mesi_name__5__Vfuncout;
    VL_ZERO_W(80, __Vfunc_tb_top__DOT__mesi_name__5__Vfuncout);
    CData/*1:0*/ __Vfunc_tb_top__DOT__mesi_name__5__s;
    __Vfunc_tb_top__DOT__mesi_name__5__s = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_top__DOT__mesi_name__6__Vfuncout;
    VL_ZERO_W(80, __Vfunc_tb_top__DOT__mesi_name__6__Vfuncout);
    CData/*1:0*/ __Vfunc_tb_top__DOT__mesi_name__6__s;
    __Vfunc_tb_top__DOT__mesi_name__6__s = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_top__DOT__mesi_name__7__Vfuncout;
    VL_ZERO_W(80, __Vfunc_tb_top__DOT__mesi_name__7__Vfuncout);
    CData/*1:0*/ __Vfunc_tb_top__DOT__mesi_name__7__s;
    __Vfunc_tb_top__DOT__mesi_name__7__s = 0;
    VlWide<8>/*255:0*/ __Vtask_tb_top__DOT__separator__8__name;
    VL_ZERO_W(256, __Vtask_tb_top__DOT__separator__8__name);
    IData/*31:0*/ __Vtask_tb_top__DOT__cpu_read__9__core;
    __Vtask_tb_top__DOT__cpu_read__9__core = 0;
    CData/*7:0*/ __Vtask_tb_top__DOT__cpu_read__9__addr;
    __Vtask_tb_top__DOT__cpu_read__9__addr = 0;
    IData/*31:0*/ __Vtask_tb_top__DOT__cpu_read__9__rdata;
    __Vtask_tb_top__DOT__cpu_read__9__rdata = 0;
    IData/*31:0*/ __Vtask_tb_top__DOT__check_data__10__actual;
    __Vtask_tb_top__DOT__check_data__10__actual = 0;
    IData/*31:0*/ __Vtask_tb_top__DOT__check_data__10__expected;
    __Vtask_tb_top__DOT__check_data__10__expected = 0;
    VlWide<4>/*127:0*/ __Vtask_tb_top__DOT__check_data__10__label;
    VL_ZERO_W(128, __Vtask_tb_top__DOT__check_data__10__label);
    IData/*31:0*/ __Vtask_tb_top__DOT__check_mesi__11__cache;
    __Vtask_tb_top__DOT__check_mesi__11__cache = 0;
    CData/*2:0*/ __Vtask_tb_top__DOT__check_mesi__11__index;
    __Vtask_tb_top__DOT__check_mesi__11__index = 0;
    CData/*1:0*/ __Vtask_tb_top__DOT__check_mesi__11__expected;
    __Vtask_tb_top__DOT__check_mesi__11__expected = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__addr_to_index__12__Vfuncout;
    __Vfunc_tb_top__DOT__addr_to_index__12__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__addr_to_index__12__a;
    __Vfunc_tb_top__DOT__addr_to_index__12__a = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_top__DOT__mesi_name__13__Vfuncout;
    VL_ZERO_W(80, __Vfunc_tb_top__DOT__mesi_name__13__Vfuncout);
    CData/*1:0*/ __Vfunc_tb_top__DOT__mesi_name__13__s;
    __Vfunc_tb_top__DOT__mesi_name__13__s = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_top__DOT__mesi_name__14__Vfuncout;
    VL_ZERO_W(80, __Vfunc_tb_top__DOT__mesi_name__14__Vfuncout);
    CData/*1:0*/ __Vfunc_tb_top__DOT__mesi_name__14__s;
    __Vfunc_tb_top__DOT__mesi_name__14__s = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_top__DOT__mesi_name__15__Vfuncout;
    VL_ZERO_W(80, __Vfunc_tb_top__DOT__mesi_name__15__Vfuncout);
    CData/*1:0*/ __Vfunc_tb_top__DOT__mesi_name__15__s;
    __Vfunc_tb_top__DOT__mesi_name__15__s = 0;
    VlWide<8>/*255:0*/ __Vtask_tb_top__DOT__separator__16__name;
    VL_ZERO_W(256, __Vtask_tb_top__DOT__separator__16__name);
    IData/*31:0*/ __Vtask_tb_top__DOT__cpu_read__17__core;
    __Vtask_tb_top__DOT__cpu_read__17__core = 0;
    CData/*7:0*/ __Vtask_tb_top__DOT__cpu_read__17__addr;
    __Vtask_tb_top__DOT__cpu_read__17__addr = 0;
    IData/*31:0*/ __Vtask_tb_top__DOT__cpu_read__17__rdata;
    __Vtask_tb_top__DOT__cpu_read__17__rdata = 0;
    IData/*31:0*/ __Vtask_tb_top__DOT__check_data__18__actual;
    __Vtask_tb_top__DOT__check_data__18__actual = 0;
    IData/*31:0*/ __Vtask_tb_top__DOT__check_data__18__expected;
    __Vtask_tb_top__DOT__check_data__18__expected = 0;
    VlWide<4>/*127:0*/ __Vtask_tb_top__DOT__check_data__18__label;
    VL_ZERO_W(128, __Vtask_tb_top__DOT__check_data__18__label);
    IData/*31:0*/ __Vtask_tb_top__DOT__check_mesi__19__cache;
    __Vtask_tb_top__DOT__check_mesi__19__cache = 0;
    CData/*2:0*/ __Vtask_tb_top__DOT__check_mesi__19__index;
    __Vtask_tb_top__DOT__check_mesi__19__index = 0;
    CData/*1:0*/ __Vtask_tb_top__DOT__check_mesi__19__expected;
    __Vtask_tb_top__DOT__check_mesi__19__expected = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__addr_to_index__20__Vfuncout;
    __Vfunc_tb_top__DOT__addr_to_index__20__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__addr_to_index__20__a;
    __Vfunc_tb_top__DOT__addr_to_index__20__a = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_top__DOT__mesi_name__21__Vfuncout;
    VL_ZERO_W(80, __Vfunc_tb_top__DOT__mesi_name__21__Vfuncout);
    CData/*1:0*/ __Vfunc_tb_top__DOT__mesi_name__21__s;
    __Vfunc_tb_top__DOT__mesi_name__21__s = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_top__DOT__mesi_name__22__Vfuncout;
    VL_ZERO_W(80, __Vfunc_tb_top__DOT__mesi_name__22__Vfuncout);
    CData/*1:0*/ __Vfunc_tb_top__DOT__mesi_name__22__s;
    __Vfunc_tb_top__DOT__mesi_name__22__s = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_top__DOT__mesi_name__23__Vfuncout;
    VL_ZERO_W(80, __Vfunc_tb_top__DOT__mesi_name__23__Vfuncout);
    CData/*1:0*/ __Vfunc_tb_top__DOT__mesi_name__23__s;
    __Vfunc_tb_top__DOT__mesi_name__23__s = 0;
    IData/*31:0*/ __Vtask_tb_top__DOT__check_mesi__24__cache;
    __Vtask_tb_top__DOT__check_mesi__24__cache = 0;
    CData/*2:0*/ __Vtask_tb_top__DOT__check_mesi__24__index;
    __Vtask_tb_top__DOT__check_mesi__24__index = 0;
    CData/*1:0*/ __Vtask_tb_top__DOT__check_mesi__24__expected;
    __Vtask_tb_top__DOT__check_mesi__24__expected = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__addr_to_index__25__Vfuncout;
    __Vfunc_tb_top__DOT__addr_to_index__25__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__addr_to_index__25__a;
    __Vfunc_tb_top__DOT__addr_to_index__25__a = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_top__DOT__mesi_name__26__Vfuncout;
    VL_ZERO_W(80, __Vfunc_tb_top__DOT__mesi_name__26__Vfuncout);
    CData/*1:0*/ __Vfunc_tb_top__DOT__mesi_name__26__s;
    __Vfunc_tb_top__DOT__mesi_name__26__s = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_top__DOT__mesi_name__27__Vfuncout;
    VL_ZERO_W(80, __Vfunc_tb_top__DOT__mesi_name__27__Vfuncout);
    CData/*1:0*/ __Vfunc_tb_top__DOT__mesi_name__27__s;
    __Vfunc_tb_top__DOT__mesi_name__27__s = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_top__DOT__mesi_name__28__Vfuncout;
    VL_ZERO_W(80, __Vfunc_tb_top__DOT__mesi_name__28__Vfuncout);
    CData/*1:0*/ __Vfunc_tb_top__DOT__mesi_name__28__s;
    __Vfunc_tb_top__DOT__mesi_name__28__s = 0;
    VlWide<8>/*255:0*/ __Vtask_tb_top__DOT__separator__29__name;
    VL_ZERO_W(256, __Vtask_tb_top__DOT__separator__29__name);
    IData/*31:0*/ __Vtask_tb_top__DOT__cpu_write__30__core;
    __Vtask_tb_top__DOT__cpu_write__30__core = 0;
    CData/*7:0*/ __Vtask_tb_top__DOT__cpu_write__30__addr;
    __Vtask_tb_top__DOT__cpu_write__30__addr = 0;
    IData/*31:0*/ __Vtask_tb_top__DOT__cpu_write__30__wdata;
    __Vtask_tb_top__DOT__cpu_write__30__wdata = 0;
    IData/*31:0*/ __Vtask_tb_top__DOT__check_mesi__31__cache;
    __Vtask_tb_top__DOT__check_mesi__31__cache = 0;
    CData/*2:0*/ __Vtask_tb_top__DOT__check_mesi__31__index;
    __Vtask_tb_top__DOT__check_mesi__31__index = 0;
    CData/*1:0*/ __Vtask_tb_top__DOT__check_mesi__31__expected;
    __Vtask_tb_top__DOT__check_mesi__31__expected = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__addr_to_index__32__Vfuncout;
    __Vfunc_tb_top__DOT__addr_to_index__32__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__addr_to_index__32__a;
    __Vfunc_tb_top__DOT__addr_to_index__32__a = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_top__DOT__mesi_name__33__Vfuncout;
    VL_ZERO_W(80, __Vfunc_tb_top__DOT__mesi_name__33__Vfuncout);
    CData/*1:0*/ __Vfunc_tb_top__DOT__mesi_name__33__s;
    __Vfunc_tb_top__DOT__mesi_name__33__s = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_top__DOT__mesi_name__34__Vfuncout;
    VL_ZERO_W(80, __Vfunc_tb_top__DOT__mesi_name__34__Vfuncout);
    CData/*1:0*/ __Vfunc_tb_top__DOT__mesi_name__34__s;
    __Vfunc_tb_top__DOT__mesi_name__34__s = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_top__DOT__mesi_name__35__Vfuncout;
    VL_ZERO_W(80, __Vfunc_tb_top__DOT__mesi_name__35__Vfuncout);
    CData/*1:0*/ __Vfunc_tb_top__DOT__mesi_name__35__s;
    __Vfunc_tb_top__DOT__mesi_name__35__s = 0;
    IData/*31:0*/ __Vtask_tb_top__DOT__check_mesi__36__cache;
    __Vtask_tb_top__DOT__check_mesi__36__cache = 0;
    CData/*2:0*/ __Vtask_tb_top__DOT__check_mesi__36__index;
    __Vtask_tb_top__DOT__check_mesi__36__index = 0;
    CData/*1:0*/ __Vtask_tb_top__DOT__check_mesi__36__expected;
    __Vtask_tb_top__DOT__check_mesi__36__expected = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__addr_to_index__37__Vfuncout;
    __Vfunc_tb_top__DOT__addr_to_index__37__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__addr_to_index__37__a;
    __Vfunc_tb_top__DOT__addr_to_index__37__a = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_top__DOT__mesi_name__38__Vfuncout;
    VL_ZERO_W(80, __Vfunc_tb_top__DOT__mesi_name__38__Vfuncout);
    CData/*1:0*/ __Vfunc_tb_top__DOT__mesi_name__38__s;
    __Vfunc_tb_top__DOT__mesi_name__38__s = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_top__DOT__mesi_name__39__Vfuncout;
    VL_ZERO_W(80, __Vfunc_tb_top__DOT__mesi_name__39__Vfuncout);
    CData/*1:0*/ __Vfunc_tb_top__DOT__mesi_name__39__s;
    __Vfunc_tb_top__DOT__mesi_name__39__s = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_top__DOT__mesi_name__40__Vfuncout;
    VL_ZERO_W(80, __Vfunc_tb_top__DOT__mesi_name__40__Vfuncout);
    CData/*1:0*/ __Vfunc_tb_top__DOT__mesi_name__40__s;
    __Vfunc_tb_top__DOT__mesi_name__40__s = 0;
    VlWide<8>/*255:0*/ __Vtask_tb_top__DOT__separator__41__name;
    VL_ZERO_W(256, __Vtask_tb_top__DOT__separator__41__name);
    IData/*31:0*/ __Vtask_tb_top__DOT__cpu_read__42__core;
    __Vtask_tb_top__DOT__cpu_read__42__core = 0;
    CData/*7:0*/ __Vtask_tb_top__DOT__cpu_read__42__addr;
    __Vtask_tb_top__DOT__cpu_read__42__addr = 0;
    IData/*31:0*/ __Vtask_tb_top__DOT__cpu_read__42__rdata;
    __Vtask_tb_top__DOT__cpu_read__42__rdata = 0;
    IData/*31:0*/ __Vtask_tb_top__DOT__check_data__43__actual;
    __Vtask_tb_top__DOT__check_data__43__actual = 0;
    IData/*31:0*/ __Vtask_tb_top__DOT__check_data__43__expected;
    __Vtask_tb_top__DOT__check_data__43__expected = 0;
    VlWide<4>/*127:0*/ __Vtask_tb_top__DOT__check_data__43__label;
    VL_ZERO_W(128, __Vtask_tb_top__DOT__check_data__43__label);
    IData/*31:0*/ __Vtask_tb_top__DOT__check_mesi__44__cache;
    __Vtask_tb_top__DOT__check_mesi__44__cache = 0;
    CData/*2:0*/ __Vtask_tb_top__DOT__check_mesi__44__index;
    __Vtask_tb_top__DOT__check_mesi__44__index = 0;
    CData/*1:0*/ __Vtask_tb_top__DOT__check_mesi__44__expected;
    __Vtask_tb_top__DOT__check_mesi__44__expected = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__addr_to_index__45__Vfuncout;
    __Vfunc_tb_top__DOT__addr_to_index__45__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__addr_to_index__45__a;
    __Vfunc_tb_top__DOT__addr_to_index__45__a = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_top__DOT__mesi_name__46__Vfuncout;
    VL_ZERO_W(80, __Vfunc_tb_top__DOT__mesi_name__46__Vfuncout);
    CData/*1:0*/ __Vfunc_tb_top__DOT__mesi_name__46__s;
    __Vfunc_tb_top__DOT__mesi_name__46__s = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_top__DOT__mesi_name__47__Vfuncout;
    VL_ZERO_W(80, __Vfunc_tb_top__DOT__mesi_name__47__Vfuncout);
    CData/*1:0*/ __Vfunc_tb_top__DOT__mesi_name__47__s;
    __Vfunc_tb_top__DOT__mesi_name__47__s = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_top__DOT__mesi_name__48__Vfuncout;
    VL_ZERO_W(80, __Vfunc_tb_top__DOT__mesi_name__48__Vfuncout);
    CData/*1:0*/ __Vfunc_tb_top__DOT__mesi_name__48__s;
    __Vfunc_tb_top__DOT__mesi_name__48__s = 0;
    IData/*31:0*/ __Vtask_tb_top__DOT__check_mesi__49__cache;
    __Vtask_tb_top__DOT__check_mesi__49__cache = 0;
    CData/*2:0*/ __Vtask_tb_top__DOT__check_mesi__49__index;
    __Vtask_tb_top__DOT__check_mesi__49__index = 0;
    CData/*1:0*/ __Vtask_tb_top__DOT__check_mesi__49__expected;
    __Vtask_tb_top__DOT__check_mesi__49__expected = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__addr_to_index__50__Vfuncout;
    __Vfunc_tb_top__DOT__addr_to_index__50__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__addr_to_index__50__a;
    __Vfunc_tb_top__DOT__addr_to_index__50__a = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_top__DOT__mesi_name__51__Vfuncout;
    VL_ZERO_W(80, __Vfunc_tb_top__DOT__mesi_name__51__Vfuncout);
    CData/*1:0*/ __Vfunc_tb_top__DOT__mesi_name__51__s;
    __Vfunc_tb_top__DOT__mesi_name__51__s = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_top__DOT__mesi_name__52__Vfuncout;
    VL_ZERO_W(80, __Vfunc_tb_top__DOT__mesi_name__52__Vfuncout);
    CData/*1:0*/ __Vfunc_tb_top__DOT__mesi_name__52__s;
    __Vfunc_tb_top__DOT__mesi_name__52__s = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_top__DOT__mesi_name__53__Vfuncout;
    VL_ZERO_W(80, __Vfunc_tb_top__DOT__mesi_name__53__Vfuncout);
    CData/*1:0*/ __Vfunc_tb_top__DOT__mesi_name__53__s;
    __Vfunc_tb_top__DOT__mesi_name__53__s = 0;
    VlWide<8>/*255:0*/ __Vtask_tb_top__DOT__separator__54__name;
    VL_ZERO_W(256, __Vtask_tb_top__DOT__separator__54__name);
    IData/*31:0*/ __Vtask_tb_top__DOT__cpu_read__55__core;
    __Vtask_tb_top__DOT__cpu_read__55__core = 0;
    CData/*7:0*/ __Vtask_tb_top__DOT__cpu_read__55__addr;
    __Vtask_tb_top__DOT__cpu_read__55__addr = 0;
    IData/*31:0*/ __Vtask_tb_top__DOT__cpu_read__55__rdata;
    __Vtask_tb_top__DOT__cpu_read__55__rdata = 0;
    IData/*31:0*/ __Vtask_tb_top__DOT__check_mesi__56__cache;
    __Vtask_tb_top__DOT__check_mesi__56__cache = 0;
    CData/*2:0*/ __Vtask_tb_top__DOT__check_mesi__56__index;
    __Vtask_tb_top__DOT__check_mesi__56__index = 0;
    CData/*1:0*/ __Vtask_tb_top__DOT__check_mesi__56__expected;
    __Vtask_tb_top__DOT__check_mesi__56__expected = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__addr_to_index__57__Vfuncout;
    __Vfunc_tb_top__DOT__addr_to_index__57__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__addr_to_index__57__a;
    __Vfunc_tb_top__DOT__addr_to_index__57__a = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_top__DOT__mesi_name__58__Vfuncout;
    VL_ZERO_W(80, __Vfunc_tb_top__DOT__mesi_name__58__Vfuncout);
    CData/*1:0*/ __Vfunc_tb_top__DOT__mesi_name__58__s;
    __Vfunc_tb_top__DOT__mesi_name__58__s = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_top__DOT__mesi_name__59__Vfuncout;
    VL_ZERO_W(80, __Vfunc_tb_top__DOT__mesi_name__59__Vfuncout);
    CData/*1:0*/ __Vfunc_tb_top__DOT__mesi_name__59__s;
    __Vfunc_tb_top__DOT__mesi_name__59__s = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_top__DOT__mesi_name__60__Vfuncout;
    VL_ZERO_W(80, __Vfunc_tb_top__DOT__mesi_name__60__Vfuncout);
    CData/*1:0*/ __Vfunc_tb_top__DOT__mesi_name__60__s;
    __Vfunc_tb_top__DOT__mesi_name__60__s = 0;
    IData/*31:0*/ __Vtask_tb_top__DOT__check_mesi__61__cache;
    __Vtask_tb_top__DOT__check_mesi__61__cache = 0;
    CData/*2:0*/ __Vtask_tb_top__DOT__check_mesi__61__index;
    __Vtask_tb_top__DOT__check_mesi__61__index = 0;
    CData/*1:0*/ __Vtask_tb_top__DOT__check_mesi__61__expected;
    __Vtask_tb_top__DOT__check_mesi__61__expected = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__addr_to_index__62__Vfuncout;
    __Vfunc_tb_top__DOT__addr_to_index__62__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__addr_to_index__62__a;
    __Vfunc_tb_top__DOT__addr_to_index__62__a = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_top__DOT__mesi_name__63__Vfuncout;
    VL_ZERO_W(80, __Vfunc_tb_top__DOT__mesi_name__63__Vfuncout);
    CData/*1:0*/ __Vfunc_tb_top__DOT__mesi_name__63__s;
    __Vfunc_tb_top__DOT__mesi_name__63__s = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_top__DOT__mesi_name__64__Vfuncout;
    VL_ZERO_W(80, __Vfunc_tb_top__DOT__mesi_name__64__Vfuncout);
    CData/*1:0*/ __Vfunc_tb_top__DOT__mesi_name__64__s;
    __Vfunc_tb_top__DOT__mesi_name__64__s = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_top__DOT__mesi_name__65__Vfuncout;
    VL_ZERO_W(80, __Vfunc_tb_top__DOT__mesi_name__65__Vfuncout);
    CData/*1:0*/ __Vfunc_tb_top__DOT__mesi_name__65__s;
    __Vfunc_tb_top__DOT__mesi_name__65__s = 0;
    IData/*31:0*/ __Vtask_tb_top__DOT__cpu_write__66__core;
    __Vtask_tb_top__DOT__cpu_write__66__core = 0;
    CData/*7:0*/ __Vtask_tb_top__DOT__cpu_write__66__addr;
    __Vtask_tb_top__DOT__cpu_write__66__addr = 0;
    IData/*31:0*/ __Vtask_tb_top__DOT__cpu_write__66__wdata;
    __Vtask_tb_top__DOT__cpu_write__66__wdata = 0;
    IData/*31:0*/ __Vtask_tb_top__DOT__check_mesi__67__cache;
    __Vtask_tb_top__DOT__check_mesi__67__cache = 0;
    CData/*2:0*/ __Vtask_tb_top__DOT__check_mesi__67__index;
    __Vtask_tb_top__DOT__check_mesi__67__index = 0;
    CData/*1:0*/ __Vtask_tb_top__DOT__check_mesi__67__expected;
    __Vtask_tb_top__DOT__check_mesi__67__expected = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__addr_to_index__68__Vfuncout;
    __Vfunc_tb_top__DOT__addr_to_index__68__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__addr_to_index__68__a;
    __Vfunc_tb_top__DOT__addr_to_index__68__a = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_top__DOT__mesi_name__69__Vfuncout;
    VL_ZERO_W(80, __Vfunc_tb_top__DOT__mesi_name__69__Vfuncout);
    CData/*1:0*/ __Vfunc_tb_top__DOT__mesi_name__69__s;
    __Vfunc_tb_top__DOT__mesi_name__69__s = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_top__DOT__mesi_name__70__Vfuncout;
    VL_ZERO_W(80, __Vfunc_tb_top__DOT__mesi_name__70__Vfuncout);
    CData/*1:0*/ __Vfunc_tb_top__DOT__mesi_name__70__s;
    __Vfunc_tb_top__DOT__mesi_name__70__s = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_top__DOT__mesi_name__71__Vfuncout;
    VL_ZERO_W(80, __Vfunc_tb_top__DOT__mesi_name__71__Vfuncout);
    CData/*1:0*/ __Vfunc_tb_top__DOT__mesi_name__71__s;
    __Vfunc_tb_top__DOT__mesi_name__71__s = 0;
    VlWide<8>/*255:0*/ __Vtask_tb_top__DOT__separator__72__name;
    VL_ZERO_W(256, __Vtask_tb_top__DOT__separator__72__name);
    IData/*31:0*/ __Vtask_tb_top__DOT__cpu_write__73__core;
    __Vtask_tb_top__DOT__cpu_write__73__core = 0;
    CData/*7:0*/ __Vtask_tb_top__DOT__cpu_write__73__addr;
    __Vtask_tb_top__DOT__cpu_write__73__addr = 0;
    IData/*31:0*/ __Vtask_tb_top__DOT__cpu_write__73__wdata;
    __Vtask_tb_top__DOT__cpu_write__73__wdata = 0;
    IData/*31:0*/ __Vtask_tb_top__DOT__check_mesi__74__cache;
    __Vtask_tb_top__DOT__check_mesi__74__cache = 0;
    CData/*2:0*/ __Vtask_tb_top__DOT__check_mesi__74__index;
    __Vtask_tb_top__DOT__check_mesi__74__index = 0;
    CData/*1:0*/ __Vtask_tb_top__DOT__check_mesi__74__expected;
    __Vtask_tb_top__DOT__check_mesi__74__expected = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__addr_to_index__75__Vfuncout;
    __Vfunc_tb_top__DOT__addr_to_index__75__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__addr_to_index__75__a;
    __Vfunc_tb_top__DOT__addr_to_index__75__a = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_top__DOT__mesi_name__76__Vfuncout;
    VL_ZERO_W(80, __Vfunc_tb_top__DOT__mesi_name__76__Vfuncout);
    CData/*1:0*/ __Vfunc_tb_top__DOT__mesi_name__76__s;
    __Vfunc_tb_top__DOT__mesi_name__76__s = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_top__DOT__mesi_name__77__Vfuncout;
    VL_ZERO_W(80, __Vfunc_tb_top__DOT__mesi_name__77__Vfuncout);
    CData/*1:0*/ __Vfunc_tb_top__DOT__mesi_name__77__s;
    __Vfunc_tb_top__DOT__mesi_name__77__s = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_top__DOT__mesi_name__78__Vfuncout;
    VL_ZERO_W(80, __Vfunc_tb_top__DOT__mesi_name__78__Vfuncout);
    CData/*1:0*/ __Vfunc_tb_top__DOT__mesi_name__78__s;
    __Vfunc_tb_top__DOT__mesi_name__78__s = 0;
    IData/*31:0*/ __Vtask_tb_top__DOT__cpu_read__79__core;
    __Vtask_tb_top__DOT__cpu_read__79__core = 0;
    CData/*7:0*/ __Vtask_tb_top__DOT__cpu_read__79__addr;
    __Vtask_tb_top__DOT__cpu_read__79__addr = 0;
    IData/*31:0*/ __Vtask_tb_top__DOT__cpu_read__79__rdata;
    __Vtask_tb_top__DOT__cpu_read__79__rdata = 0;
    IData/*31:0*/ __Vtask_tb_top__DOT__check_data__80__actual;
    __Vtask_tb_top__DOT__check_data__80__actual = 0;
    IData/*31:0*/ __Vtask_tb_top__DOT__check_data__80__expected;
    __Vtask_tb_top__DOT__check_data__80__expected = 0;
    VlWide<4>/*127:0*/ __Vtask_tb_top__DOT__check_data__80__label;
    VL_ZERO_W(128, __Vtask_tb_top__DOT__check_data__80__label);
    VlWide<8>/*255:0*/ __Vtask_tb_top__DOT__separator__81__name;
    VL_ZERO_W(256, __Vtask_tb_top__DOT__separator__81__name);
    IData/*31:0*/ __Vtask_tb_top__DOT__cpu_write__82__core;
    __Vtask_tb_top__DOT__cpu_write__82__core = 0;
    CData/*7:0*/ __Vtask_tb_top__DOT__cpu_write__82__addr;
    __Vtask_tb_top__DOT__cpu_write__82__addr = 0;
    IData/*31:0*/ __Vtask_tb_top__DOT__cpu_write__82__wdata;
    __Vtask_tb_top__DOT__cpu_write__82__wdata = 0;
    IData/*31:0*/ __Vtask_tb_top__DOT__check_mesi__83__cache;
    __Vtask_tb_top__DOT__check_mesi__83__cache = 0;
    CData/*2:0*/ __Vtask_tb_top__DOT__check_mesi__83__index;
    __Vtask_tb_top__DOT__check_mesi__83__index = 0;
    CData/*1:0*/ __Vtask_tb_top__DOT__check_mesi__83__expected;
    __Vtask_tb_top__DOT__check_mesi__83__expected = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__addr_to_index__84__Vfuncout;
    __Vfunc_tb_top__DOT__addr_to_index__84__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__addr_to_index__84__a;
    __Vfunc_tb_top__DOT__addr_to_index__84__a = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_top__DOT__mesi_name__85__Vfuncout;
    VL_ZERO_W(80, __Vfunc_tb_top__DOT__mesi_name__85__Vfuncout);
    CData/*1:0*/ __Vfunc_tb_top__DOT__mesi_name__85__s;
    __Vfunc_tb_top__DOT__mesi_name__85__s = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_top__DOT__mesi_name__86__Vfuncout;
    VL_ZERO_W(80, __Vfunc_tb_top__DOT__mesi_name__86__Vfuncout);
    CData/*1:0*/ __Vfunc_tb_top__DOT__mesi_name__86__s;
    __Vfunc_tb_top__DOT__mesi_name__86__s = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_top__DOT__mesi_name__87__Vfuncout;
    VL_ZERO_W(80, __Vfunc_tb_top__DOT__mesi_name__87__Vfuncout);
    CData/*1:0*/ __Vfunc_tb_top__DOT__mesi_name__87__s;
    __Vfunc_tb_top__DOT__mesi_name__87__s = 0;
    IData/*31:0*/ __Vtask_tb_top__DOT__check_mesi__88__cache;
    __Vtask_tb_top__DOT__check_mesi__88__cache = 0;
    CData/*2:0*/ __Vtask_tb_top__DOT__check_mesi__88__index;
    __Vtask_tb_top__DOT__check_mesi__88__index = 0;
    CData/*1:0*/ __Vtask_tb_top__DOT__check_mesi__88__expected;
    __Vtask_tb_top__DOT__check_mesi__88__expected = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__addr_to_index__89__Vfuncout;
    __Vfunc_tb_top__DOT__addr_to_index__89__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__addr_to_index__89__a;
    __Vfunc_tb_top__DOT__addr_to_index__89__a = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_top__DOT__mesi_name__90__Vfuncout;
    VL_ZERO_W(80, __Vfunc_tb_top__DOT__mesi_name__90__Vfuncout);
    CData/*1:0*/ __Vfunc_tb_top__DOT__mesi_name__90__s;
    __Vfunc_tb_top__DOT__mesi_name__90__s = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_top__DOT__mesi_name__91__Vfuncout;
    VL_ZERO_W(80, __Vfunc_tb_top__DOT__mesi_name__91__Vfuncout);
    CData/*1:0*/ __Vfunc_tb_top__DOT__mesi_name__91__s;
    __Vfunc_tb_top__DOT__mesi_name__91__s = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_top__DOT__mesi_name__92__Vfuncout;
    VL_ZERO_W(80, __Vfunc_tb_top__DOT__mesi_name__92__Vfuncout);
    CData/*1:0*/ __Vfunc_tb_top__DOT__mesi_name__92__s;
    __Vfunc_tb_top__DOT__mesi_name__92__s = 0;
    IData/*31:0*/ __Vtask_tb_top__DOT__cpu_write__93__core;
    __Vtask_tb_top__DOT__cpu_write__93__core = 0;
    CData/*7:0*/ __Vtask_tb_top__DOT__cpu_write__93__addr;
    __Vtask_tb_top__DOT__cpu_write__93__addr = 0;
    IData/*31:0*/ __Vtask_tb_top__DOT__cpu_write__93__wdata;
    __Vtask_tb_top__DOT__cpu_write__93__wdata = 0;
    IData/*31:0*/ __Vtask_tb_top__DOT__check_mesi__94__cache;
    __Vtask_tb_top__DOT__check_mesi__94__cache = 0;
    CData/*2:0*/ __Vtask_tb_top__DOT__check_mesi__94__index;
    __Vtask_tb_top__DOT__check_mesi__94__index = 0;
    CData/*1:0*/ __Vtask_tb_top__DOT__check_mesi__94__expected;
    __Vtask_tb_top__DOT__check_mesi__94__expected = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__addr_to_index__95__Vfuncout;
    __Vfunc_tb_top__DOT__addr_to_index__95__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__addr_to_index__95__a;
    __Vfunc_tb_top__DOT__addr_to_index__95__a = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_top__DOT__mesi_name__96__Vfuncout;
    VL_ZERO_W(80, __Vfunc_tb_top__DOT__mesi_name__96__Vfuncout);
    CData/*1:0*/ __Vfunc_tb_top__DOT__mesi_name__96__s;
    __Vfunc_tb_top__DOT__mesi_name__96__s = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_top__DOT__mesi_name__97__Vfuncout;
    VL_ZERO_W(80, __Vfunc_tb_top__DOT__mesi_name__97__Vfuncout);
    CData/*1:0*/ __Vfunc_tb_top__DOT__mesi_name__97__s;
    __Vfunc_tb_top__DOT__mesi_name__97__s = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_top__DOT__mesi_name__98__Vfuncout;
    VL_ZERO_W(80, __Vfunc_tb_top__DOT__mesi_name__98__Vfuncout);
    CData/*1:0*/ __Vfunc_tb_top__DOT__mesi_name__98__s;
    __Vfunc_tb_top__DOT__mesi_name__98__s = 0;
    IData/*31:0*/ __Vtask_tb_top__DOT__check_mesi__99__cache;
    __Vtask_tb_top__DOT__check_mesi__99__cache = 0;
    CData/*2:0*/ __Vtask_tb_top__DOT__check_mesi__99__index;
    __Vtask_tb_top__DOT__check_mesi__99__index = 0;
    CData/*1:0*/ __Vtask_tb_top__DOT__check_mesi__99__expected;
    __Vtask_tb_top__DOT__check_mesi__99__expected = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__addr_to_index__100__Vfuncout;
    __Vfunc_tb_top__DOT__addr_to_index__100__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__addr_to_index__100__a;
    __Vfunc_tb_top__DOT__addr_to_index__100__a = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_top__DOT__mesi_name__101__Vfuncout;
    VL_ZERO_W(80, __Vfunc_tb_top__DOT__mesi_name__101__Vfuncout);
    CData/*1:0*/ __Vfunc_tb_top__DOT__mesi_name__101__s;
    __Vfunc_tb_top__DOT__mesi_name__101__s = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_top__DOT__mesi_name__102__Vfuncout;
    VL_ZERO_W(80, __Vfunc_tb_top__DOT__mesi_name__102__Vfuncout);
    CData/*1:0*/ __Vfunc_tb_top__DOT__mesi_name__102__s;
    __Vfunc_tb_top__DOT__mesi_name__102__s = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_top__DOT__mesi_name__103__Vfuncout;
    VL_ZERO_W(80, __Vfunc_tb_top__DOT__mesi_name__103__Vfuncout);
    CData/*1:0*/ __Vfunc_tb_top__DOT__mesi_name__103__s;
    __Vfunc_tb_top__DOT__mesi_name__103__s = 0;
    VlWide<8>/*255:0*/ __Vtask_tb_top__DOT__separator__104__name;
    VL_ZERO_W(256, __Vtask_tb_top__DOT__separator__104__name);
    IData/*31:0*/ __Vtask_tb_top__DOT__cpu_read__105__core;
    __Vtask_tb_top__DOT__cpu_read__105__core = 0;
    CData/*7:0*/ __Vtask_tb_top__DOT__cpu_read__105__addr;
    __Vtask_tb_top__DOT__cpu_read__105__addr = 0;
    IData/*31:0*/ __Vtask_tb_top__DOT__cpu_read__105__rdata;
    __Vtask_tb_top__DOT__cpu_read__105__rdata = 0;
    IData/*31:0*/ __Vtask_tb_top__DOT__check_data__106__actual;
    __Vtask_tb_top__DOT__check_data__106__actual = 0;
    IData/*31:0*/ __Vtask_tb_top__DOT__check_data__106__expected;
    __Vtask_tb_top__DOT__check_data__106__expected = 0;
    VlWide<4>/*127:0*/ __Vtask_tb_top__DOT__check_data__106__label;
    VL_ZERO_W(128, __Vtask_tb_top__DOT__check_data__106__label);
    VlWide<8>/*255:0*/ __Vtask_tb_top__DOT__separator__107__name;
    VL_ZERO_W(256, __Vtask_tb_top__DOT__separator__107__name);
    VlWide<8>/*255:0*/ __Vtask_tb_top__DOT__separator__108__name;
    VL_ZERO_W(256, __Vtask_tb_top__DOT__separator__108__name);
    VlWide<4>/*127:0*/ __Vtemp_1;
    // Body
    vlSelf->tb_top__DOT__errors = 0U;
    __Vtemp_1[0U] = 0x2e766364U;
    __Vtemp_1[1U] = 0x2f73696dU;
    __Vtemp_1[2U] = 0x6d6f7574U;
    __Vtemp_1[3U] = 0x7369U;
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(4, __Vtemp_1));
    vlSymsp->_traceDumpOpen();
    vlSelf->tb_top__DOT__c0_req = 0U;
    vlSelf->tb_top__DOT__c0_we = 0U;
    vlSelf->tb_top__DOT__c0_addr = 0U;
    vlSelf->tb_top__DOT__c0_wdata = 0U;
    vlSelf->tb_top__DOT__c1_req = 0U;
    vlSelf->tb_top__DOT__c1_we = 0U;
    vlSelf->tb_top__DOT__c1_addr = 0U;
    vlSelf->tb_top__DOT__c1_wdata = 0U;
    co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_top.clk)", 
                                                       "tb/tb_mesi_system.v", 
                                                       281);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_top.clk)", 
                                                       "tb/tb_mesi_system.v", 
                                                       281);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_top.clk)", 
                                                       "tb/tb_mesi_system.v", 
                                                       281);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_top.clk)", 
                                                       "tb/tb_mesi_system.v", 
                                                       281);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb_top__DOT__rst = 0U;
    co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_top.clk)", 
                                                       "tb/tb_mesi_system.v", 
                                                       283);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_top.clk)", 
                                                       "tb/tb_mesi_system.v", 
                                                       283);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_tb_top__DOT__separator__0__name[0U] = Vtb_top__ConstPool__CONST_h2409fbff_0[0U];
    __Vtask_tb_top__DOT__separator__0__name[1U] = Vtb_top__ConstPool__CONST_h2409fbff_0[1U];
    __Vtask_tb_top__DOT__separator__0__name[2U] = Vtb_top__ConstPool__CONST_h2409fbff_0[2U];
    __Vtask_tb_top__DOT__separator__0__name[3U] = Vtb_top__ConstPool__CONST_h2409fbff_0[3U];
    __Vtask_tb_top__DOT__separator__0__name[4U] = Vtb_top__ConstPool__CONST_h2409fbff_0[4U];
    __Vtask_tb_top__DOT__separator__0__name[5U] = Vtb_top__ConstPool__CONST_h2409fbff_0[5U];
    __Vtask_tb_top__DOT__separator__0__name[6U] = Vtb_top__ConstPool__CONST_h2409fbff_0[6U];
    __Vtask_tb_top__DOT__separator__0__name[7U] = Vtb_top__ConstPool__CONST_h2409fbff_0[7U];
    VL_WRITEF("\n============================================================\n %s\n============================================================\n  Memory pre-fill: word[n] = n\n  0x10 -> word index 4 -> expected value 4\n\n",
              256,__Vtask_tb_top__DOT__separator__0__name.data());
    vlSelf->tb_top__DOT__bus_rd_before = vlSelf->tb_top__DOT__cnt_busrd;
    __Vtask_tb_top__DOT__cpu_read__1__addr = 0x10U;
    __Vtask_tb_top__DOT__cpu_read__1__core = 0U;
    vlSelf->tb_top__DOT__cpu_read__Vstatic__timeout = 0U;
    if ((0U == __Vtask_tb_top__DOT__cpu_read__1__core)) {
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           151);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c0_req = 1U;
        vlSelf->tb_top__DOT__c0_we = 0U;
        vlSelf->tb_top__DOT__c0_addr = __Vtask_tb_top__DOT__cpu_read__1__addr;
        co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           153);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        while (((~ (IData)(vlSelf->tb_top__DOT__c0_ack)) 
                & VL_GTS_III(32, 0x32U, vlSelf->tb_top__DOT__cpu_read__Vstatic__timeout))) {
            co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_top.clk)", 
                                                               "tb/tb_mesi_system.v", 
                                                               155);
            vlSelf->__Vm_traceActivity[2U] = 1U;
            vlSelf->tb_top__DOT__cpu_read__Vstatic__timeout 
                = ((IData)(1U) + vlSelf->tb_top__DOT__cpu_read__Vstatic__timeout);
        }
        __Vtask_tb_top__DOT__cpu_read__1__rdata = vlSelf->tb_top__DOT__c0_rdata;
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           159);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c0_req = 0U;
    } else {
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           162);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c1_req = 1U;
        vlSelf->tb_top__DOT__c1_we = 0U;
        vlSelf->tb_top__DOT__c1_addr = __Vtask_tb_top__DOT__cpu_read__1__addr;
        co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           164);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        while (((~ (IData)(vlSelf->tb_top__DOT__c1_ack)) 
                & VL_GTS_III(32, 0x32U, vlSelf->tb_top__DOT__cpu_read__Vstatic__timeout))) {
            co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_top.clk)", 
                                                               "tb/tb_mesi_system.v", 
                                                               166);
            vlSelf->__Vm_traceActivity[2U] = 1U;
            vlSelf->tb_top__DOT__cpu_read__Vstatic__timeout 
                = ((IData)(1U) + vlSelf->tb_top__DOT__cpu_read__Vstatic__timeout);
        }
        __Vtask_tb_top__DOT__cpu_read__1__rdata = vlSelf->tb_top__DOT__c1_rdata;
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           170);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c1_req = 0U;
    }
    if (VL_UNLIKELY(VL_LTES_III(32, 0x32U, vlSelf->tb_top__DOT__cpu_read__Vstatic__timeout))) {
        VL_WRITEF("  [WARN] cpu_read core%0d timed out!\n",
                  32,__Vtask_tb_top__DOT__cpu_read__1__core);
    }
    vlSelf->tb_top__DOT__rdata0 = __Vtask_tb_top__DOT__cpu_read__1__rdata;
    VL_WRITEF("  Core 0 got: 0x%08x\n",32,vlSelf->tb_top__DOT__rdata0);
    __Vtask_tb_top__DOT__check_data__2__label[0U] = 0x64203429U;
    __Vtask_tb_top__DOT__check_data__2__label[1U] = 0x28776f72U;
    __Vtask_tb_top__DOT__check_data__2__label[2U] = 0x61746120U;
    __Vtask_tb_top__DOT__check_data__2__label[3U] = 0x30207264U;
    __Vtask_tb_top__DOT__check_data__2__expected = 4U;
    __Vtask_tb_top__DOT__check_data__2__actual = vlSelf->tb_top__DOT__rdata0;
    if ((__Vtask_tb_top__DOT__check_data__2__actual 
         == __Vtask_tb_top__DOT__check_data__2__expected)) {
        VL_WRITEF("  [PASS] %s = 0x%08x\n",128,__Vtask_tb_top__DOT__check_data__2__label.data(),
                  32,__Vtask_tb_top__DOT__check_data__2__actual);
    } else {
        VL_WRITEF("  [FAIL] %s = 0x%08x  (expected 0x%08x)\n",
                  128,__Vtask_tb_top__DOT__check_data__2__label.data(),
                  32,__Vtask_tb_top__DOT__check_data__2__actual,
                  32,__Vtask_tb_top__DOT__check_data__2__expected);
        vlSelf->tb_top__DOT__errors = ((IData)(1U) 
                                       + vlSelf->tb_top__DOT__errors);
    }
    __Vtask_tb_top__DOT__check_mesi__3__expected = 2U;
    __Vfunc_tb_top__DOT__addr_to_index__4__a = 0x10U;
    __Vfunc_tb_top__DOT__addr_to_index__4__Vfuncout 
        = (7U & ((IData)(__Vfunc_tb_top__DOT__addr_to_index__4__a) 
                 >> 2U));
    __Vtask_tb_top__DOT__check_mesi__3__index = __Vfunc_tb_top__DOT__addr_to_index__4__Vfuncout;
    __Vtask_tb_top__DOT__check_mesi__3__cache = 0U;
    vlSelf->tb_top__DOT__check_mesi__Vstatic__actual 
        = ((0U == __Vtask_tb_top__DOT__check_mesi__3__cache)
            ? vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi
           [__Vtask_tb_top__DOT__check_mesi__3__index]
            : vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi
           [__Vtask_tb_top__DOT__check_mesi__3__index]);
    if (((IData)(vlSelf->tb_top__DOT__check_mesi__Vstatic__actual) 
         == (IData)(__Vtask_tb_top__DOT__check_mesi__3__expected))) {
        VL_WRITEF("  [PASS] Cache%0d index%0# state = %s\n",
                  32,__Vtask_tb_top__DOT__check_mesi__3__cache,
                  3,(IData)(__Vtask_tb_top__DOT__check_mesi__3__index),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__5__s 
                            = vlSelf->tb_top__DOT__check_mesi__Vstatic__actual;
                        __Vfunc_tb_top__DOT__mesi_name__5__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__5__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__5__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__5__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__5__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__5__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__5__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__5__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__5__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__5__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__5__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__5__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__5__Vfuncout).data());
    } else {
        VL_WRITEF("  [FAIL] Cache%0d index%0# state = %s  (expected %s)\n",
                  32,__Vtask_tb_top__DOT__check_mesi__3__cache,
                  3,(IData)(__Vtask_tb_top__DOT__check_mesi__3__index),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__6__s 
                            = vlSelf->tb_top__DOT__check_mesi__Vstatic__actual;
                        __Vfunc_tb_top__DOT__mesi_name__6__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__6__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__6__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__6__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__6__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__6__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__6__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__6__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__6__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__6__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__6__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__6__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__6__Vfuncout).data(),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__7__s 
                            = __Vtask_tb_top__DOT__check_mesi__3__expected;
                        __Vfunc_tb_top__DOT__mesi_name__7__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__7__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__7__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__7__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__7__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__7__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__7__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__7__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__7__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__7__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__7__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__7__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__7__Vfuncout).data());
        vlSelf->tb_top__DOT__errors = ((IData)(1U) 
                                       + vlSelf->tb_top__DOT__errors);
    }
    VL_WRITEF("  Bus BusRd count: %0d (expected 1)\n",
              32,(vlSelf->tb_top__DOT__cnt_busrd - vlSelf->tb_top__DOT__bus_rd_before));
    co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_top.clk)", 
                                                       "tb/tb_mesi_system.v", 
                                                       302);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_top.clk)", 
                                                       "tb/tb_mesi_system.v", 
                                                       302);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_tb_top__DOT__separator__8__name[0U] = Vtb_top__ConstPool__CONST_h5130200a_0[0U];
    __Vtask_tb_top__DOT__separator__8__name[1U] = Vtb_top__ConstPool__CONST_h5130200a_0[1U];
    __Vtask_tb_top__DOT__separator__8__name[2U] = Vtb_top__ConstPool__CONST_h5130200a_0[2U];
    __Vtask_tb_top__DOT__separator__8__name[3U] = Vtb_top__ConstPool__CONST_h5130200a_0[3U];
    __Vtask_tb_top__DOT__separator__8__name[4U] = Vtb_top__ConstPool__CONST_h5130200a_0[4U];
    __Vtask_tb_top__DOT__separator__8__name[5U] = Vtb_top__ConstPool__CONST_h5130200a_0[5U];
    __Vtask_tb_top__DOT__separator__8__name[6U] = Vtb_top__ConstPool__CONST_h5130200a_0[6U];
    __Vtask_tb_top__DOT__separator__8__name[7U] = Vtb_top__ConstPool__CONST_h5130200a_0[7U];
    VL_WRITEF("\n============================================================\n %s\n============================================================\n",
              256,__Vtask_tb_top__DOT__separator__8__name.data());
    vlSelf->tb_top__DOT__bus_rd_before = vlSelf->tb_top__DOT__cnt_busrd;
    __Vtask_tb_top__DOT__cpu_read__9__addr = 0x10U;
    __Vtask_tb_top__DOT__cpu_read__9__core = 0U;
    vlSelf->tb_top__DOT__cpu_read__Vstatic__timeout = 0U;
    if ((0U == __Vtask_tb_top__DOT__cpu_read__9__core)) {
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           151);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c0_req = 1U;
        vlSelf->tb_top__DOT__c0_we = 0U;
        vlSelf->tb_top__DOT__c0_addr = __Vtask_tb_top__DOT__cpu_read__9__addr;
        co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           153);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        while (((~ (IData)(vlSelf->tb_top__DOT__c0_ack)) 
                & VL_GTS_III(32, 0x32U, vlSelf->tb_top__DOT__cpu_read__Vstatic__timeout))) {
            co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_top.clk)", 
                                                               "tb/tb_mesi_system.v", 
                                                               155);
            vlSelf->__Vm_traceActivity[2U] = 1U;
            vlSelf->tb_top__DOT__cpu_read__Vstatic__timeout 
                = ((IData)(1U) + vlSelf->tb_top__DOT__cpu_read__Vstatic__timeout);
        }
        __Vtask_tb_top__DOT__cpu_read__9__rdata = vlSelf->tb_top__DOT__c0_rdata;
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           159);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c0_req = 0U;
    } else {
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           162);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c1_req = 1U;
        vlSelf->tb_top__DOT__c1_we = 0U;
        vlSelf->tb_top__DOT__c1_addr = __Vtask_tb_top__DOT__cpu_read__9__addr;
        co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           164);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        while (((~ (IData)(vlSelf->tb_top__DOT__c1_ack)) 
                & VL_GTS_III(32, 0x32U, vlSelf->tb_top__DOT__cpu_read__Vstatic__timeout))) {
            co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_top.clk)", 
                                                               "tb/tb_mesi_system.v", 
                                                               166);
            vlSelf->__Vm_traceActivity[2U] = 1U;
            vlSelf->tb_top__DOT__cpu_read__Vstatic__timeout 
                = ((IData)(1U) + vlSelf->tb_top__DOT__cpu_read__Vstatic__timeout);
        }
        __Vtask_tb_top__DOT__cpu_read__9__rdata = vlSelf->tb_top__DOT__c1_rdata;
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           170);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c1_req = 0U;
    }
    if (VL_UNLIKELY(VL_LTES_III(32, 0x32U, vlSelf->tb_top__DOT__cpu_read__Vstatic__timeout))) {
        VL_WRITEF("  [WARN] cpu_read core%0d timed out!\n",
                  32,__Vtask_tb_top__DOT__cpu_read__9__core);
    }
    vlSelf->tb_top__DOT__rdata0 = __Vtask_tb_top__DOT__cpu_read__9__rdata;
    __Vtask_tb_top__DOT__check_data__10__label[0U] = 0x68697429U;
    __Vtask_tb_top__DOT__check_data__10__label[1U] = 0x74612028U;
    __Vtask_tb_top__DOT__check_data__10__label[2U] = 0x20726461U;
    __Vtask_tb_top__DOT__check_data__10__label[3U] = 0x6f726530U;
    __Vtask_tb_top__DOT__check_data__10__expected = 4U;
    __Vtask_tb_top__DOT__check_data__10__actual = vlSelf->tb_top__DOT__rdata0;
    if ((__Vtask_tb_top__DOT__check_data__10__actual 
         == __Vtask_tb_top__DOT__check_data__10__expected)) {
        VL_WRITEF("  [PASS] %s = 0x%08x\n",128,__Vtask_tb_top__DOT__check_data__10__label.data(),
                  32,__Vtask_tb_top__DOT__check_data__10__actual);
    } else {
        VL_WRITEF("  [FAIL] %s = 0x%08x  (expected 0x%08x)\n",
                  128,__Vtask_tb_top__DOT__check_data__10__label.data(),
                  32,__Vtask_tb_top__DOT__check_data__10__actual,
                  32,__Vtask_tb_top__DOT__check_data__10__expected);
        vlSelf->tb_top__DOT__errors = ((IData)(1U) 
                                       + vlSelf->tb_top__DOT__errors);
    }
    __Vtask_tb_top__DOT__check_mesi__11__expected = 2U;
    __Vfunc_tb_top__DOT__addr_to_index__12__a = 0x10U;
    __Vfunc_tb_top__DOT__addr_to_index__12__Vfuncout 
        = (7U & ((IData)(__Vfunc_tb_top__DOT__addr_to_index__12__a) 
                 >> 2U));
    __Vtask_tb_top__DOT__check_mesi__11__index = __Vfunc_tb_top__DOT__addr_to_index__12__Vfuncout;
    __Vtask_tb_top__DOT__check_mesi__11__cache = 0U;
    vlSelf->tb_top__DOT__check_mesi__Vstatic__actual 
        = ((0U == __Vtask_tb_top__DOT__check_mesi__11__cache)
            ? vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi
           [__Vtask_tb_top__DOT__check_mesi__11__index]
            : vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi
           [__Vtask_tb_top__DOT__check_mesi__11__index]);
    if (((IData)(vlSelf->tb_top__DOT__check_mesi__Vstatic__actual) 
         == (IData)(__Vtask_tb_top__DOT__check_mesi__11__expected))) {
        VL_WRITEF("  [PASS] Cache%0d index%0# state = %s\n",
                  32,__Vtask_tb_top__DOT__check_mesi__11__cache,
                  3,(IData)(__Vtask_tb_top__DOT__check_mesi__11__index),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__13__s 
                            = vlSelf->tb_top__DOT__check_mesi__Vstatic__actual;
                        __Vfunc_tb_top__DOT__mesi_name__13__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__13__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__13__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__13__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__13__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__13__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__13__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__13__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__13__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__13__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__13__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__13__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__13__Vfuncout).data());
    } else {
        VL_WRITEF("  [FAIL] Cache%0d index%0# state = %s  (expected %s)\n",
                  32,__Vtask_tb_top__DOT__check_mesi__11__cache,
                  3,(IData)(__Vtask_tb_top__DOT__check_mesi__11__index),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__14__s 
                            = vlSelf->tb_top__DOT__check_mesi__Vstatic__actual;
                        __Vfunc_tb_top__DOT__mesi_name__14__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__14__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__14__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__14__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__14__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__14__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__14__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__14__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__14__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__14__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__14__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__14__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__14__Vfuncout).data(),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__15__s 
                            = __Vtask_tb_top__DOT__check_mesi__11__expected;
                        __Vfunc_tb_top__DOT__mesi_name__15__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__15__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__15__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__15__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__15__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__15__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__15__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__15__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__15__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__15__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__15__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__15__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__15__Vfuncout).data());
        vlSelf->tb_top__DOT__errors = ((IData)(1U) 
                                       + vlSelf->tb_top__DOT__errors);
    }
    VL_WRITEF("  Bus BusRd count since test: %0d (expected 0 - served from cache)\n",
              32,(vlSelf->tb_top__DOT__cnt_busrd - vlSelf->tb_top__DOT__bus_rd_before));
    co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_top.clk)", 
                                                       "tb/tb_mesi_system.v", 
                                                       316);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_top.clk)", 
                                                       "tb/tb_mesi_system.v", 
                                                       316);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_tb_top__DOT__separator__16__name[0U] = 
        Vtb_top__ConstPool__CONST_h20ae5363_0[0U];
    __Vtask_tb_top__DOT__separator__16__name[1U] = 
        Vtb_top__ConstPool__CONST_h20ae5363_0[1U];
    __Vtask_tb_top__DOT__separator__16__name[2U] = 
        Vtb_top__ConstPool__CONST_h20ae5363_0[2U];
    __Vtask_tb_top__DOT__separator__16__name[3U] = 
        Vtb_top__ConstPool__CONST_h20ae5363_0[3U];
    __Vtask_tb_top__DOT__separator__16__name[4U] = 
        Vtb_top__ConstPool__CONST_h20ae5363_0[4U];
    __Vtask_tb_top__DOT__separator__16__name[5U] = 
        Vtb_top__ConstPool__CONST_h20ae5363_0[5U];
    __Vtask_tb_top__DOT__separator__16__name[6U] = 
        Vtb_top__ConstPool__CONST_h20ae5363_0[6U];
    __Vtask_tb_top__DOT__separator__16__name[7U] = 
        Vtb_top__ConstPool__CONST_h20ae5363_0[7U];
    VL_WRITEF("\n============================================================\n %s\n============================================================\n",
              256,__Vtask_tb_top__DOT__separator__16__name.data());
    vlSelf->tb_top__DOT__bus_rd_before = vlSelf->tb_top__DOT__cnt_busrd;
    __Vtask_tb_top__DOT__cpu_read__17__addr = 0x10U;
    __Vtask_tb_top__DOT__cpu_read__17__core = 1U;
    vlSelf->tb_top__DOT__cpu_read__Vstatic__timeout = 0U;
    if ((0U == __Vtask_tb_top__DOT__cpu_read__17__core)) {
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           151);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c0_req = 1U;
        vlSelf->tb_top__DOT__c0_we = 0U;
        vlSelf->tb_top__DOT__c0_addr = __Vtask_tb_top__DOT__cpu_read__17__addr;
        co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           153);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        while (((~ (IData)(vlSelf->tb_top__DOT__c0_ack)) 
                & VL_GTS_III(32, 0x32U, vlSelf->tb_top__DOT__cpu_read__Vstatic__timeout))) {
            co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_top.clk)", 
                                                               "tb/tb_mesi_system.v", 
                                                               155);
            vlSelf->__Vm_traceActivity[2U] = 1U;
            vlSelf->tb_top__DOT__cpu_read__Vstatic__timeout 
                = ((IData)(1U) + vlSelf->tb_top__DOT__cpu_read__Vstatic__timeout);
        }
        __Vtask_tb_top__DOT__cpu_read__17__rdata = vlSelf->tb_top__DOT__c0_rdata;
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           159);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c0_req = 0U;
    } else {
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           162);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c1_req = 1U;
        vlSelf->tb_top__DOT__c1_we = 0U;
        vlSelf->tb_top__DOT__c1_addr = __Vtask_tb_top__DOT__cpu_read__17__addr;
        co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           164);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        while (((~ (IData)(vlSelf->tb_top__DOT__c1_ack)) 
                & VL_GTS_III(32, 0x32U, vlSelf->tb_top__DOT__cpu_read__Vstatic__timeout))) {
            co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_top.clk)", 
                                                               "tb/tb_mesi_system.v", 
                                                               166);
            vlSelf->__Vm_traceActivity[2U] = 1U;
            vlSelf->tb_top__DOT__cpu_read__Vstatic__timeout 
                = ((IData)(1U) + vlSelf->tb_top__DOT__cpu_read__Vstatic__timeout);
        }
        __Vtask_tb_top__DOT__cpu_read__17__rdata = vlSelf->tb_top__DOT__c1_rdata;
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           170);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c1_req = 0U;
    }
    if (VL_UNLIKELY(VL_LTES_III(32, 0x32U, vlSelf->tb_top__DOT__cpu_read__Vstatic__timeout))) {
        VL_WRITEF("  [WARN] cpu_read core%0d timed out!\n",
                  32,__Vtask_tb_top__DOT__cpu_read__17__core);
    }
    vlSelf->tb_top__DOT__rdata1 = __Vtask_tb_top__DOT__cpu_read__17__rdata;
    __Vtask_tb_top__DOT__check_data__18__label[0U] = 0x72656429U;
    __Vtask_tb_top__DOT__check_data__18__label[1U] = 0x28736861U;
    __Vtask_tb_top__DOT__check_data__18__label[2U] = 0x61746120U;
    __Vtask_tb_top__DOT__check_data__18__label[3U] = 0x31207264U;
    __Vtask_tb_top__DOT__check_data__18__expected = 4U;
    __Vtask_tb_top__DOT__check_data__18__actual = vlSelf->tb_top__DOT__rdata1;
    if ((__Vtask_tb_top__DOT__check_data__18__actual 
         == __Vtask_tb_top__DOT__check_data__18__expected)) {
        VL_WRITEF("  [PASS] %s = 0x%08x\n",128,__Vtask_tb_top__DOT__check_data__18__label.data(),
                  32,__Vtask_tb_top__DOT__check_data__18__actual);
    } else {
        VL_WRITEF("  [FAIL] %s = 0x%08x  (expected 0x%08x)\n",
                  128,__Vtask_tb_top__DOT__check_data__18__label.data(),
                  32,__Vtask_tb_top__DOT__check_data__18__actual,
                  32,__Vtask_tb_top__DOT__check_data__18__expected);
        vlSelf->tb_top__DOT__errors = ((IData)(1U) 
                                       + vlSelf->tb_top__DOT__errors);
    }
    __Vtask_tb_top__DOT__check_mesi__19__expected = 1U;
    __Vfunc_tb_top__DOT__addr_to_index__20__a = 0x10U;
    __Vfunc_tb_top__DOT__addr_to_index__20__Vfuncout 
        = (7U & ((IData)(__Vfunc_tb_top__DOT__addr_to_index__20__a) 
                 >> 2U));
    __Vtask_tb_top__DOT__check_mesi__19__index = __Vfunc_tb_top__DOT__addr_to_index__20__Vfuncout;
    __Vtask_tb_top__DOT__check_mesi__19__cache = 0U;
    vlSelf->tb_top__DOT__check_mesi__Vstatic__actual 
        = ((0U == __Vtask_tb_top__DOT__check_mesi__19__cache)
            ? vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi
           [__Vtask_tb_top__DOT__check_mesi__19__index]
            : vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi
           [__Vtask_tb_top__DOT__check_mesi__19__index]);
    if (((IData)(vlSelf->tb_top__DOT__check_mesi__Vstatic__actual) 
         == (IData)(__Vtask_tb_top__DOT__check_mesi__19__expected))) {
        VL_WRITEF("  [PASS] Cache%0d index%0# state = %s\n",
                  32,__Vtask_tb_top__DOT__check_mesi__19__cache,
                  3,(IData)(__Vtask_tb_top__DOT__check_mesi__19__index),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__21__s 
                            = vlSelf->tb_top__DOT__check_mesi__Vstatic__actual;
                        __Vfunc_tb_top__DOT__mesi_name__21__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__21__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__21__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__21__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__21__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__21__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__21__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__21__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__21__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__21__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__21__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__21__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__21__Vfuncout).data());
    } else {
        VL_WRITEF("  [FAIL] Cache%0d index%0# state = %s  (expected %s)\n",
                  32,__Vtask_tb_top__DOT__check_mesi__19__cache,
                  3,(IData)(__Vtask_tb_top__DOT__check_mesi__19__index),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__22__s 
                            = vlSelf->tb_top__DOT__check_mesi__Vstatic__actual;
                        __Vfunc_tb_top__DOT__mesi_name__22__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__22__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__22__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__22__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__22__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__22__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__22__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__22__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__22__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__22__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__22__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__22__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__22__Vfuncout).data(),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__23__s 
                            = __Vtask_tb_top__DOT__check_mesi__19__expected;
                        __Vfunc_tb_top__DOT__mesi_name__23__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__23__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__23__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__23__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__23__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__23__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__23__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__23__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__23__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__23__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__23__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__23__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__23__Vfuncout).data());
        vlSelf->tb_top__DOT__errors = ((IData)(1U) 
                                       + vlSelf->tb_top__DOT__errors);
    }
    __Vtask_tb_top__DOT__check_mesi__24__expected = 1U;
    __Vfunc_tb_top__DOT__addr_to_index__25__a = 0x10U;
    __Vfunc_tb_top__DOT__addr_to_index__25__Vfuncout 
        = (7U & ((IData)(__Vfunc_tb_top__DOT__addr_to_index__25__a) 
                 >> 2U));
    __Vtask_tb_top__DOT__check_mesi__24__index = __Vfunc_tb_top__DOT__addr_to_index__25__Vfuncout;
    __Vtask_tb_top__DOT__check_mesi__24__cache = 1U;
    vlSelf->tb_top__DOT__check_mesi__Vstatic__actual 
        = ((0U == __Vtask_tb_top__DOT__check_mesi__24__cache)
            ? vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi
           [__Vtask_tb_top__DOT__check_mesi__24__index]
            : vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi
           [__Vtask_tb_top__DOT__check_mesi__24__index]);
    if (((IData)(vlSelf->tb_top__DOT__check_mesi__Vstatic__actual) 
         == (IData)(__Vtask_tb_top__DOT__check_mesi__24__expected))) {
        VL_WRITEF("  [PASS] Cache%0d index%0# state = %s\n",
                  32,__Vtask_tb_top__DOT__check_mesi__24__cache,
                  3,(IData)(__Vtask_tb_top__DOT__check_mesi__24__index),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__26__s 
                            = vlSelf->tb_top__DOT__check_mesi__Vstatic__actual;
                        __Vfunc_tb_top__DOT__mesi_name__26__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__26__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__26__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__26__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__26__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__26__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__26__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__26__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__26__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__26__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__26__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__26__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__26__Vfuncout).data());
    } else {
        VL_WRITEF("  [FAIL] Cache%0d index%0# state = %s  (expected %s)\n",
                  32,__Vtask_tb_top__DOT__check_mesi__24__cache,
                  3,(IData)(__Vtask_tb_top__DOT__check_mesi__24__index),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__27__s 
                            = vlSelf->tb_top__DOT__check_mesi__Vstatic__actual;
                        __Vfunc_tb_top__DOT__mesi_name__27__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__27__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__27__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__27__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__27__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__27__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__27__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__27__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__27__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__27__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__27__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__27__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__27__Vfuncout).data(),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__28__s 
                            = __Vtask_tb_top__DOT__check_mesi__24__expected;
                        __Vfunc_tb_top__DOT__mesi_name__28__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__28__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__28__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__28__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__28__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__28__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__28__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__28__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__28__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__28__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__28__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__28__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__28__Vfuncout).data());
        vlSelf->tb_top__DOT__errors = ((IData)(1U) 
                                       + vlSelf->tb_top__DOT__errors);
    }
    VL_WRITEF("  Bus BusRd count since test: %0d (expected 1)\n",
              32,(vlSelf->tb_top__DOT__cnt_busrd - vlSelf->tb_top__DOT__bus_rd_before));
    co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_top.clk)", 
                                                       "tb/tb_mesi_system.v", 
                                                       330);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_top.clk)", 
                                                       "tb/tb_mesi_system.v", 
                                                       330);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_tb_top__DOT__separator__29__name[0U] = 
        Vtb_top__ConstPool__CONST_ha0ca69a4_0[0U];
    __Vtask_tb_top__DOT__separator__29__name[1U] = 
        Vtb_top__ConstPool__CONST_ha0ca69a4_0[1U];
    __Vtask_tb_top__DOT__separator__29__name[2U] = 
        Vtb_top__ConstPool__CONST_ha0ca69a4_0[2U];
    __Vtask_tb_top__DOT__separator__29__name[3U] = 
        Vtb_top__ConstPool__CONST_ha0ca69a4_0[3U];
    __Vtask_tb_top__DOT__separator__29__name[4U] = 
        Vtb_top__ConstPool__CONST_ha0ca69a4_0[4U];
    __Vtask_tb_top__DOT__separator__29__name[5U] = 
        Vtb_top__ConstPool__CONST_ha0ca69a4_0[5U];
    __Vtask_tb_top__DOT__separator__29__name[6U] = 
        Vtb_top__ConstPool__CONST_ha0ca69a4_0[6U];
    __Vtask_tb_top__DOT__separator__29__name[7U] = 
        Vtb_top__ConstPool__CONST_ha0ca69a4_0[7U];
    VL_WRITEF("\n============================================================\n %s\n============================================================\n",
              256,__Vtask_tb_top__DOT__separator__29__name.data());
    vlSelf->tb_top__DOT__bus_inv_before = vlSelf->tb_top__DOT__cnt_busInv;
    __Vtask_tb_top__DOT__cpu_write__30__wdata = 0xdeadbeefU;
    __Vtask_tb_top__DOT__cpu_write__30__addr = 0x10U;
    __Vtask_tb_top__DOT__cpu_write__30__core = 0U;
    vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout = 0U;
    if ((0U == __Vtask_tb_top__DOT__cpu_write__30__core)) {
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           188);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c0_req = 1U;
        vlSelf->tb_top__DOT__c0_we = 1U;
        vlSelf->tb_top__DOT__c0_addr = __Vtask_tb_top__DOT__cpu_write__30__addr;
        vlSelf->tb_top__DOT__c0_wdata = __Vtask_tb_top__DOT__cpu_write__30__wdata;
        co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           190);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        while (((~ (IData)(vlSelf->tb_top__DOT__c0_ack)) 
                & VL_GTS_III(32, 0x32U, vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout))) {
            co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_top.clk)", 
                                                               "tb/tb_mesi_system.v", 
                                                               192);
            vlSelf->__Vm_traceActivity[2U] = 1U;
            vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout 
                = ((IData)(1U) + vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout);
        }
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           195);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c0_req = 0U;
        vlSelf->tb_top__DOT__c0_we = 0U;
    } else {
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           198);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c1_req = 1U;
        vlSelf->tb_top__DOT__c1_we = 1U;
        vlSelf->tb_top__DOT__c1_addr = __Vtask_tb_top__DOT__cpu_write__30__addr;
        vlSelf->tb_top__DOT__c1_wdata = __Vtask_tb_top__DOT__cpu_write__30__wdata;
        co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           200);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        while (((~ (IData)(vlSelf->tb_top__DOT__c1_ack)) 
                & VL_GTS_III(32, 0x32U, vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout))) {
            co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_top.clk)", 
                                                               "tb/tb_mesi_system.v", 
                                                               202);
            vlSelf->__Vm_traceActivity[2U] = 1U;
            vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout 
                = ((IData)(1U) + vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout);
        }
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           205);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c1_req = 0U;
        vlSelf->tb_top__DOT__c1_we = 0U;
    }
    if (VL_UNLIKELY(VL_LTES_III(32, 0x32U, vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout))) {
        VL_WRITEF("  [WARN] cpu_write core%0d timed out!\n",
                  32,__Vtask_tb_top__DOT__cpu_write__30__core);
    }
    __Vtask_tb_top__DOT__check_mesi__31__expected = 3U;
    __Vfunc_tb_top__DOT__addr_to_index__32__a = 0x10U;
    __Vfunc_tb_top__DOT__addr_to_index__32__Vfuncout 
        = (7U & ((IData)(__Vfunc_tb_top__DOT__addr_to_index__32__a) 
                 >> 2U));
    __Vtask_tb_top__DOT__check_mesi__31__index = __Vfunc_tb_top__DOT__addr_to_index__32__Vfuncout;
    __Vtask_tb_top__DOT__check_mesi__31__cache = 0U;
    vlSelf->tb_top__DOT__check_mesi__Vstatic__actual 
        = ((0U == __Vtask_tb_top__DOT__check_mesi__31__cache)
            ? vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi
           [__Vtask_tb_top__DOT__check_mesi__31__index]
            : vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi
           [__Vtask_tb_top__DOT__check_mesi__31__index]);
    if (((IData)(vlSelf->tb_top__DOT__check_mesi__Vstatic__actual) 
         == (IData)(__Vtask_tb_top__DOT__check_mesi__31__expected))) {
        VL_WRITEF("  [PASS] Cache%0d index%0# state = %s\n",
                  32,__Vtask_tb_top__DOT__check_mesi__31__cache,
                  3,(IData)(__Vtask_tb_top__DOT__check_mesi__31__index),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__33__s 
                            = vlSelf->tb_top__DOT__check_mesi__Vstatic__actual;
                        __Vfunc_tb_top__DOT__mesi_name__33__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__33__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__33__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__33__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__33__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__33__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__33__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__33__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__33__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__33__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__33__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__33__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__33__Vfuncout).data());
    } else {
        VL_WRITEF("  [FAIL] Cache%0d index%0# state = %s  (expected %s)\n",
                  32,__Vtask_tb_top__DOT__check_mesi__31__cache,
                  3,(IData)(__Vtask_tb_top__DOT__check_mesi__31__index),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__34__s 
                            = vlSelf->tb_top__DOT__check_mesi__Vstatic__actual;
                        __Vfunc_tb_top__DOT__mesi_name__34__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__34__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__34__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__34__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__34__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__34__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__34__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__34__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__34__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__34__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__34__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__34__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__34__Vfuncout).data(),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__35__s 
                            = __Vtask_tb_top__DOT__check_mesi__31__expected;
                        __Vfunc_tb_top__DOT__mesi_name__35__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__35__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__35__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__35__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__35__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__35__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__35__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__35__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__35__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__35__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__35__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__35__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__35__Vfuncout).data());
        vlSelf->tb_top__DOT__errors = ((IData)(1U) 
                                       + vlSelf->tb_top__DOT__errors);
    }
    __Vtask_tb_top__DOT__check_mesi__36__expected = 0U;
    __Vfunc_tb_top__DOT__addr_to_index__37__a = 0x10U;
    __Vfunc_tb_top__DOT__addr_to_index__37__Vfuncout 
        = (7U & ((IData)(__Vfunc_tb_top__DOT__addr_to_index__37__a) 
                 >> 2U));
    __Vtask_tb_top__DOT__check_mesi__36__index = __Vfunc_tb_top__DOT__addr_to_index__37__Vfuncout;
    __Vtask_tb_top__DOT__check_mesi__36__cache = 1U;
    vlSelf->tb_top__DOT__check_mesi__Vstatic__actual 
        = ((0U == __Vtask_tb_top__DOT__check_mesi__36__cache)
            ? vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi
           [__Vtask_tb_top__DOT__check_mesi__36__index]
            : vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi
           [__Vtask_tb_top__DOT__check_mesi__36__index]);
    if (((IData)(vlSelf->tb_top__DOT__check_mesi__Vstatic__actual) 
         == (IData)(__Vtask_tb_top__DOT__check_mesi__36__expected))) {
        VL_WRITEF("  [PASS] Cache%0d index%0# state = %s\n",
                  32,__Vtask_tb_top__DOT__check_mesi__36__cache,
                  3,(IData)(__Vtask_tb_top__DOT__check_mesi__36__index),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__38__s 
                            = vlSelf->tb_top__DOT__check_mesi__Vstatic__actual;
                        __Vfunc_tb_top__DOT__mesi_name__38__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__38__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__38__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__38__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__38__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__38__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__38__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__38__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__38__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__38__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__38__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__38__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__38__Vfuncout).data());
    } else {
        VL_WRITEF("  [FAIL] Cache%0d index%0# state = %s  (expected %s)\n",
                  32,__Vtask_tb_top__DOT__check_mesi__36__cache,
                  3,(IData)(__Vtask_tb_top__DOT__check_mesi__36__index),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__39__s 
                            = vlSelf->tb_top__DOT__check_mesi__Vstatic__actual;
                        __Vfunc_tb_top__DOT__mesi_name__39__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__39__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__39__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__39__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__39__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__39__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__39__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__39__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__39__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__39__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__39__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__39__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__39__Vfuncout).data(),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__40__s 
                            = __Vtask_tb_top__DOT__check_mesi__36__expected;
                        __Vfunc_tb_top__DOT__mesi_name__40__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__40__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__40__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__40__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__40__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__40__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__40__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__40__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__40__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__40__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__40__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__40__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__40__Vfuncout).data());
        vlSelf->tb_top__DOT__errors = ((IData)(1U) 
                                       + vlSelf->tb_top__DOT__errors);
    }
    VL_WRITEF("  Bus BusInv count since test: %0d (expected 1)\n",
              32,(vlSelf->tb_top__DOT__cnt_busInv - vlSelf->tb_top__DOT__bus_inv_before));
    co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_top.clk)", 
                                                       "tb/tb_mesi_system.v", 
                                                       344);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_top.clk)", 
                                                       "tb/tb_mesi_system.v", 
                                                       344);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_tb_top__DOT__separator__41__name[0U] = 
        Vtb_top__ConstPool__CONST_hd636e1b5_0[0U];
    __Vtask_tb_top__DOT__separator__41__name[1U] = 
        Vtb_top__ConstPool__CONST_hd636e1b5_0[1U];
    __Vtask_tb_top__DOT__separator__41__name[2U] = 
        Vtb_top__ConstPool__CONST_hd636e1b5_0[2U];
    __Vtask_tb_top__DOT__separator__41__name[3U] = 
        Vtb_top__ConstPool__CONST_hd636e1b5_0[3U];
    __Vtask_tb_top__DOT__separator__41__name[4U] = 
        Vtb_top__ConstPool__CONST_hd636e1b5_0[4U];
    __Vtask_tb_top__DOT__separator__41__name[5U] = 
        Vtb_top__ConstPool__CONST_hd636e1b5_0[5U];
    __Vtask_tb_top__DOT__separator__41__name[6U] = 
        Vtb_top__ConstPool__CONST_hd636e1b5_0[6U];
    __Vtask_tb_top__DOT__separator__41__name[7U] = 
        Vtb_top__ConstPool__CONST_hd636e1b5_0[7U];
    VL_WRITEF("\n============================================================\n %s\n============================================================\n",
              256,__Vtask_tb_top__DOT__separator__41__name.data());
    vlSelf->tb_top__DOT__bus_rd_before = vlSelf->tb_top__DOT__cnt_busrd;
    __Vtask_tb_top__DOT__cpu_read__42__addr = 0x10U;
    __Vtask_tb_top__DOT__cpu_read__42__core = 1U;
    vlSelf->tb_top__DOT__cpu_read__Vstatic__timeout = 0U;
    if ((0U == __Vtask_tb_top__DOT__cpu_read__42__core)) {
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           151);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c0_req = 1U;
        vlSelf->tb_top__DOT__c0_we = 0U;
        vlSelf->tb_top__DOT__c0_addr = __Vtask_tb_top__DOT__cpu_read__42__addr;
        co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           153);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        while (((~ (IData)(vlSelf->tb_top__DOT__c0_ack)) 
                & VL_GTS_III(32, 0x32U, vlSelf->tb_top__DOT__cpu_read__Vstatic__timeout))) {
            co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_top.clk)", 
                                                               "tb/tb_mesi_system.v", 
                                                               155);
            vlSelf->__Vm_traceActivity[2U] = 1U;
            vlSelf->tb_top__DOT__cpu_read__Vstatic__timeout 
                = ((IData)(1U) + vlSelf->tb_top__DOT__cpu_read__Vstatic__timeout);
        }
        __Vtask_tb_top__DOT__cpu_read__42__rdata = vlSelf->tb_top__DOT__c0_rdata;
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           159);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c0_req = 0U;
    } else {
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           162);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c1_req = 1U;
        vlSelf->tb_top__DOT__c1_we = 0U;
        vlSelf->tb_top__DOT__c1_addr = __Vtask_tb_top__DOT__cpu_read__42__addr;
        co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           164);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        while (((~ (IData)(vlSelf->tb_top__DOT__c1_ack)) 
                & VL_GTS_III(32, 0x32U, vlSelf->tb_top__DOT__cpu_read__Vstatic__timeout))) {
            co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_top.clk)", 
                                                               "tb/tb_mesi_system.v", 
                                                               166);
            vlSelf->__Vm_traceActivity[2U] = 1U;
            vlSelf->tb_top__DOT__cpu_read__Vstatic__timeout 
                = ((IData)(1U) + vlSelf->tb_top__DOT__cpu_read__Vstatic__timeout);
        }
        __Vtask_tb_top__DOT__cpu_read__42__rdata = vlSelf->tb_top__DOT__c1_rdata;
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           170);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c1_req = 0U;
    }
    if (VL_UNLIKELY(VL_LTES_III(32, 0x32U, vlSelf->tb_top__DOT__cpu_read__Vstatic__timeout))) {
        VL_WRITEF("  [WARN] cpu_read core%0d timed out!\n",
                  32,__Vtask_tb_top__DOT__cpu_read__42__core);
    }
    vlSelf->tb_top__DOT__rdata1 = __Vtask_tb_top__DOT__cpu_read__42__rdata;
    __Vtask_tb_top__DOT__check_data__43__label[0U] = 0x65203029U;
    __Vtask_tb_top__DOT__check_data__43__label[1U] = 0x20436f72U;
    __Vtask_tb_top__DOT__check_data__43__label[2U] = 0x69727479U;
    __Vtask_tb_top__DOT__check_data__43__label[3U] = 0x6f6d2064U;
    __Vtask_tb_top__DOT__check_data__43__expected = 0xdeadbeefU;
    __Vtask_tb_top__DOT__check_data__43__actual = vlSelf->tb_top__DOT__rdata1;
    if ((__Vtask_tb_top__DOT__check_data__43__actual 
         == __Vtask_tb_top__DOT__check_data__43__expected)) {
        VL_WRITEF("  [PASS] %s = 0x%08x\n",128,__Vtask_tb_top__DOT__check_data__43__label.data(),
                  32,__Vtask_tb_top__DOT__check_data__43__actual);
    } else {
        VL_WRITEF("  [FAIL] %s = 0x%08x  (expected 0x%08x)\n",
                  128,__Vtask_tb_top__DOT__check_data__43__label.data(),
                  32,__Vtask_tb_top__DOT__check_data__43__actual,
                  32,__Vtask_tb_top__DOT__check_data__43__expected);
        vlSelf->tb_top__DOT__errors = ((IData)(1U) 
                                       + vlSelf->tb_top__DOT__errors);
    }
    __Vtask_tb_top__DOT__check_mesi__44__expected = 1U;
    __Vfunc_tb_top__DOT__addr_to_index__45__a = 0x10U;
    __Vfunc_tb_top__DOT__addr_to_index__45__Vfuncout 
        = (7U & ((IData)(__Vfunc_tb_top__DOT__addr_to_index__45__a) 
                 >> 2U));
    __Vtask_tb_top__DOT__check_mesi__44__index = __Vfunc_tb_top__DOT__addr_to_index__45__Vfuncout;
    __Vtask_tb_top__DOT__check_mesi__44__cache = 0U;
    vlSelf->tb_top__DOT__check_mesi__Vstatic__actual 
        = ((0U == __Vtask_tb_top__DOT__check_mesi__44__cache)
            ? vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi
           [__Vtask_tb_top__DOT__check_mesi__44__index]
            : vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi
           [__Vtask_tb_top__DOT__check_mesi__44__index]);
    if (((IData)(vlSelf->tb_top__DOT__check_mesi__Vstatic__actual) 
         == (IData)(__Vtask_tb_top__DOT__check_mesi__44__expected))) {
        VL_WRITEF("  [PASS] Cache%0d index%0# state = %s\n",
                  32,__Vtask_tb_top__DOT__check_mesi__44__cache,
                  3,(IData)(__Vtask_tb_top__DOT__check_mesi__44__index),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__46__s 
                            = vlSelf->tb_top__DOT__check_mesi__Vstatic__actual;
                        __Vfunc_tb_top__DOT__mesi_name__46__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__46__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__46__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__46__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__46__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__46__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__46__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__46__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__46__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__46__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__46__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__46__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__46__Vfuncout).data());
    } else {
        VL_WRITEF("  [FAIL] Cache%0d index%0# state = %s  (expected %s)\n",
                  32,__Vtask_tb_top__DOT__check_mesi__44__cache,
                  3,(IData)(__Vtask_tb_top__DOT__check_mesi__44__index),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__47__s 
                            = vlSelf->tb_top__DOT__check_mesi__Vstatic__actual;
                        __Vfunc_tb_top__DOT__mesi_name__47__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__47__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__47__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__47__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__47__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__47__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__47__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__47__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__47__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__47__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__47__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__47__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__47__Vfuncout).data(),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__48__s 
                            = __Vtask_tb_top__DOT__check_mesi__44__expected;
                        __Vfunc_tb_top__DOT__mesi_name__48__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__48__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__48__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__48__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__48__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__48__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__48__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__48__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__48__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__48__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__48__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__48__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__48__Vfuncout).data());
        vlSelf->tb_top__DOT__errors = ((IData)(1U) 
                                       + vlSelf->tb_top__DOT__errors);
    }
    __Vtask_tb_top__DOT__check_mesi__49__expected = 1U;
    __Vfunc_tb_top__DOT__addr_to_index__50__a = 0x10U;
    __Vfunc_tb_top__DOT__addr_to_index__50__Vfuncout 
        = (7U & ((IData)(__Vfunc_tb_top__DOT__addr_to_index__50__a) 
                 >> 2U));
    __Vtask_tb_top__DOT__check_mesi__49__index = __Vfunc_tb_top__DOT__addr_to_index__50__Vfuncout;
    __Vtask_tb_top__DOT__check_mesi__49__cache = 1U;
    vlSelf->tb_top__DOT__check_mesi__Vstatic__actual 
        = ((0U == __Vtask_tb_top__DOT__check_mesi__49__cache)
            ? vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi
           [__Vtask_tb_top__DOT__check_mesi__49__index]
            : vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi
           [__Vtask_tb_top__DOT__check_mesi__49__index]);
    if (((IData)(vlSelf->tb_top__DOT__check_mesi__Vstatic__actual) 
         == (IData)(__Vtask_tb_top__DOT__check_mesi__49__expected))) {
        VL_WRITEF("  [PASS] Cache%0d index%0# state = %s\n",
                  32,__Vtask_tb_top__DOT__check_mesi__49__cache,
                  3,(IData)(__Vtask_tb_top__DOT__check_mesi__49__index),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__51__s 
                            = vlSelf->tb_top__DOT__check_mesi__Vstatic__actual;
                        __Vfunc_tb_top__DOT__mesi_name__51__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__51__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__51__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__51__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__51__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__51__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__51__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__51__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__51__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__51__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__51__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__51__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__51__Vfuncout).data());
    } else {
        VL_WRITEF("  [FAIL] Cache%0d index%0# state = %s  (expected %s)\n",
                  32,__Vtask_tb_top__DOT__check_mesi__49__cache,
                  3,(IData)(__Vtask_tb_top__DOT__check_mesi__49__index),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__52__s 
                            = vlSelf->tb_top__DOT__check_mesi__Vstatic__actual;
                        __Vfunc_tb_top__DOT__mesi_name__52__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__52__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__52__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__52__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__52__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__52__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__52__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__52__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__52__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__52__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__52__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__52__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__52__Vfuncout).data(),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__53__s 
                            = __Vtask_tb_top__DOT__check_mesi__49__expected;
                        __Vfunc_tb_top__DOT__mesi_name__53__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__53__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__53__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__53__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__53__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__53__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__53__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__53__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__53__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__53__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__53__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__53__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__53__Vfuncout).data());
        vlSelf->tb_top__DOT__errors = ((IData)(1U) 
                                       + vlSelf->tb_top__DOT__errors);
    }
    VL_WRITEF("  Bus BusRd count since test: %0d (expected 1)\n",
              32,(vlSelf->tb_top__DOT__cnt_busrd - vlSelf->tb_top__DOT__bus_rd_before));
    co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_top.clk)", 
                                                       "tb/tb_mesi_system.v", 
                                                       359);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_top.clk)", 
                                                       "tb/tb_mesi_system.v", 
                                                       359);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_tb_top__DOT__separator__54__name[0U] = 
        Vtb_top__ConstPool__CONST_h5972b5a4_0[0U];
    __Vtask_tb_top__DOT__separator__54__name[1U] = 
        Vtb_top__ConstPool__CONST_h5972b5a4_0[1U];
    __Vtask_tb_top__DOT__separator__54__name[2U] = 
        Vtb_top__ConstPool__CONST_h5972b5a4_0[2U];
    __Vtask_tb_top__DOT__separator__54__name[3U] = 
        Vtb_top__ConstPool__CONST_h5972b5a4_0[3U];
    __Vtask_tb_top__DOT__separator__54__name[4U] = 
        Vtb_top__ConstPool__CONST_h5972b5a4_0[4U];
    __Vtask_tb_top__DOT__separator__54__name[5U] = 
        Vtb_top__ConstPool__CONST_h5972b5a4_0[5U];
    __Vtask_tb_top__DOT__separator__54__name[6U] = 
        Vtb_top__ConstPool__CONST_h5972b5a4_0[6U];
    __Vtask_tb_top__DOT__separator__54__name[7U] = 
        Vtb_top__ConstPool__CONST_h5972b5a4_0[7U];
    VL_WRITEF("\n============================================================\n %s\n============================================================\n",
              256,__Vtask_tb_top__DOT__separator__54__name.data());
    vlSelf->tb_top__DOT__bus_inv_before = vlSelf->tb_top__DOT__cnt_busInv;
    __Vtask_tb_top__DOT__cpu_read__55__addr = 0x20U;
    __Vtask_tb_top__DOT__cpu_read__55__core = 1U;
    vlSelf->tb_top__DOT__cpu_read__Vstatic__timeout = 0U;
    if ((0U == __Vtask_tb_top__DOT__cpu_read__55__core)) {
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           151);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c0_req = 1U;
        vlSelf->tb_top__DOT__c0_we = 0U;
        vlSelf->tb_top__DOT__c0_addr = __Vtask_tb_top__DOT__cpu_read__55__addr;
        co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           153);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        while (((~ (IData)(vlSelf->tb_top__DOT__c0_ack)) 
                & VL_GTS_III(32, 0x32U, vlSelf->tb_top__DOT__cpu_read__Vstatic__timeout))) {
            co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_top.clk)", 
                                                               "tb/tb_mesi_system.v", 
                                                               155);
            vlSelf->__Vm_traceActivity[2U] = 1U;
            vlSelf->tb_top__DOT__cpu_read__Vstatic__timeout 
                = ((IData)(1U) + vlSelf->tb_top__DOT__cpu_read__Vstatic__timeout);
        }
        __Vtask_tb_top__DOT__cpu_read__55__rdata = vlSelf->tb_top__DOT__c0_rdata;
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           159);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c0_req = 0U;
    } else {
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           162);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c1_req = 1U;
        vlSelf->tb_top__DOT__c1_we = 0U;
        vlSelf->tb_top__DOT__c1_addr = __Vtask_tb_top__DOT__cpu_read__55__addr;
        co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           164);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        while (((~ (IData)(vlSelf->tb_top__DOT__c1_ack)) 
                & VL_GTS_III(32, 0x32U, vlSelf->tb_top__DOT__cpu_read__Vstatic__timeout))) {
            co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_top.clk)", 
                                                               "tb/tb_mesi_system.v", 
                                                               166);
            vlSelf->__Vm_traceActivity[2U] = 1U;
            vlSelf->tb_top__DOT__cpu_read__Vstatic__timeout 
                = ((IData)(1U) + vlSelf->tb_top__DOT__cpu_read__Vstatic__timeout);
        }
        __Vtask_tb_top__DOT__cpu_read__55__rdata = vlSelf->tb_top__DOT__c1_rdata;
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           170);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c1_req = 0U;
    }
    if (VL_UNLIKELY(VL_LTES_III(32, 0x32U, vlSelf->tb_top__DOT__cpu_read__Vstatic__timeout))) {
        VL_WRITEF("  [WARN] cpu_read core%0d timed out!\n",
                  32,__Vtask_tb_top__DOT__cpu_read__55__core);
    }
    vlSelf->tb_top__DOT__rdata1 = __Vtask_tb_top__DOT__cpu_read__55__rdata;
    __Vtask_tb_top__DOT__check_mesi__56__expected = 2U;
    __Vfunc_tb_top__DOT__addr_to_index__57__a = 0x20U;
    __Vfunc_tb_top__DOT__addr_to_index__57__Vfuncout 
        = (7U & ((IData)(__Vfunc_tb_top__DOT__addr_to_index__57__a) 
                 >> 2U));
    __Vtask_tb_top__DOT__check_mesi__56__index = __Vfunc_tb_top__DOT__addr_to_index__57__Vfuncout;
    __Vtask_tb_top__DOT__check_mesi__56__cache = 1U;
    vlSelf->tb_top__DOT__check_mesi__Vstatic__actual 
        = ((0U == __Vtask_tb_top__DOT__check_mesi__56__cache)
            ? vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi
           [__Vtask_tb_top__DOT__check_mesi__56__index]
            : vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi
           [__Vtask_tb_top__DOT__check_mesi__56__index]);
    if (((IData)(vlSelf->tb_top__DOT__check_mesi__Vstatic__actual) 
         == (IData)(__Vtask_tb_top__DOT__check_mesi__56__expected))) {
        VL_WRITEF("  [PASS] Cache%0d index%0# state = %s\n",
                  32,__Vtask_tb_top__DOT__check_mesi__56__cache,
                  3,(IData)(__Vtask_tb_top__DOT__check_mesi__56__index),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__58__s 
                            = vlSelf->tb_top__DOT__check_mesi__Vstatic__actual;
                        __Vfunc_tb_top__DOT__mesi_name__58__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__58__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__58__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__58__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__58__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__58__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__58__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__58__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__58__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__58__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__58__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__58__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__58__Vfuncout).data());
    } else {
        VL_WRITEF("  [FAIL] Cache%0d index%0# state = %s  (expected %s)\n",
                  32,__Vtask_tb_top__DOT__check_mesi__56__cache,
                  3,(IData)(__Vtask_tb_top__DOT__check_mesi__56__index),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__59__s 
                            = vlSelf->tb_top__DOT__check_mesi__Vstatic__actual;
                        __Vfunc_tb_top__DOT__mesi_name__59__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__59__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__59__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__59__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__59__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__59__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__59__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__59__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__59__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__59__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__59__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__59__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__59__Vfuncout).data(),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__60__s 
                            = __Vtask_tb_top__DOT__check_mesi__56__expected;
                        __Vfunc_tb_top__DOT__mesi_name__60__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__60__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__60__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__60__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__60__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__60__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__60__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__60__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__60__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__60__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__60__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__60__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__60__Vfuncout).data());
        vlSelf->tb_top__DOT__errors = ((IData)(1U) 
                                       + vlSelf->tb_top__DOT__errors);
    }
    __Vtask_tb_top__DOT__check_mesi__61__expected = 0U;
    __Vfunc_tb_top__DOT__addr_to_index__62__a = 0x20U;
    __Vfunc_tb_top__DOT__addr_to_index__62__Vfuncout 
        = (7U & ((IData)(__Vfunc_tb_top__DOT__addr_to_index__62__a) 
                 >> 2U));
    __Vtask_tb_top__DOT__check_mesi__61__index = __Vfunc_tb_top__DOT__addr_to_index__62__Vfuncout;
    __Vtask_tb_top__DOT__check_mesi__61__cache = 0U;
    vlSelf->tb_top__DOT__check_mesi__Vstatic__actual 
        = ((0U == __Vtask_tb_top__DOT__check_mesi__61__cache)
            ? vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi
           [__Vtask_tb_top__DOT__check_mesi__61__index]
            : vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi
           [__Vtask_tb_top__DOT__check_mesi__61__index]);
    if (((IData)(vlSelf->tb_top__DOT__check_mesi__Vstatic__actual) 
         == (IData)(__Vtask_tb_top__DOT__check_mesi__61__expected))) {
        VL_WRITEF("  [PASS] Cache%0d index%0# state = %s\n",
                  32,__Vtask_tb_top__DOT__check_mesi__61__cache,
                  3,(IData)(__Vtask_tb_top__DOT__check_mesi__61__index),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__63__s 
                            = vlSelf->tb_top__DOT__check_mesi__Vstatic__actual;
                        __Vfunc_tb_top__DOT__mesi_name__63__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__63__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__63__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__63__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__63__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__63__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__63__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__63__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__63__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__63__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__63__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__63__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__63__Vfuncout).data());
    } else {
        VL_WRITEF("  [FAIL] Cache%0d index%0# state = %s  (expected %s)\n",
                  32,__Vtask_tb_top__DOT__check_mesi__61__cache,
                  3,(IData)(__Vtask_tb_top__DOT__check_mesi__61__index),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__64__s 
                            = vlSelf->tb_top__DOT__check_mesi__Vstatic__actual;
                        __Vfunc_tb_top__DOT__mesi_name__64__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__64__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__64__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__64__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__64__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__64__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__64__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__64__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__64__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__64__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__64__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__64__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__64__Vfuncout).data(),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__65__s 
                            = __Vtask_tb_top__DOT__check_mesi__61__expected;
                        __Vfunc_tb_top__DOT__mesi_name__65__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__65__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__65__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__65__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__65__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__65__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__65__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__65__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__65__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__65__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__65__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__65__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__65__Vfuncout).data());
        vlSelf->tb_top__DOT__errors = ((IData)(1U) 
                                       + vlSelf->tb_top__DOT__errors);
    }
    __Vtask_tb_top__DOT__cpu_write__66__wdata = 0xcafe0001U;
    __Vtask_tb_top__DOT__cpu_write__66__addr = 0x20U;
    __Vtask_tb_top__DOT__cpu_write__66__core = 1U;
    vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout = 0U;
    if ((0U == __Vtask_tb_top__DOT__cpu_write__66__core)) {
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           188);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c0_req = 1U;
        vlSelf->tb_top__DOT__c0_we = 1U;
        vlSelf->tb_top__DOT__c0_addr = __Vtask_tb_top__DOT__cpu_write__66__addr;
        vlSelf->tb_top__DOT__c0_wdata = __Vtask_tb_top__DOT__cpu_write__66__wdata;
        co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           190);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        while (((~ (IData)(vlSelf->tb_top__DOT__c0_ack)) 
                & VL_GTS_III(32, 0x32U, vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout))) {
            co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_top.clk)", 
                                                               "tb/tb_mesi_system.v", 
                                                               192);
            vlSelf->__Vm_traceActivity[2U] = 1U;
            vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout 
                = ((IData)(1U) + vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout);
        }
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           195);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c0_req = 0U;
        vlSelf->tb_top__DOT__c0_we = 0U;
    } else {
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           198);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c1_req = 1U;
        vlSelf->tb_top__DOT__c1_we = 1U;
        vlSelf->tb_top__DOT__c1_addr = __Vtask_tb_top__DOT__cpu_write__66__addr;
        vlSelf->tb_top__DOT__c1_wdata = __Vtask_tb_top__DOT__cpu_write__66__wdata;
        co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           200);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        while (((~ (IData)(vlSelf->tb_top__DOT__c1_ack)) 
                & VL_GTS_III(32, 0x32U, vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout))) {
            co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_top.clk)", 
                                                               "tb/tb_mesi_system.v", 
                                                               202);
            vlSelf->__Vm_traceActivity[2U] = 1U;
            vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout 
                = ((IData)(1U) + vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout);
        }
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           205);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c1_req = 0U;
        vlSelf->tb_top__DOT__c1_we = 0U;
    }
    if (VL_UNLIKELY(VL_LTES_III(32, 0x32U, vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout))) {
        VL_WRITEF("  [WARN] cpu_write core%0d timed out!\n",
                  32,__Vtask_tb_top__DOT__cpu_write__66__core);
    }
    __Vtask_tb_top__DOT__check_mesi__67__expected = 3U;
    __Vfunc_tb_top__DOT__addr_to_index__68__a = 0x20U;
    __Vfunc_tb_top__DOT__addr_to_index__68__Vfuncout 
        = (7U & ((IData)(__Vfunc_tb_top__DOT__addr_to_index__68__a) 
                 >> 2U));
    __Vtask_tb_top__DOT__check_mesi__67__index = __Vfunc_tb_top__DOT__addr_to_index__68__Vfuncout;
    __Vtask_tb_top__DOT__check_mesi__67__cache = 1U;
    vlSelf->tb_top__DOT__check_mesi__Vstatic__actual 
        = ((0U == __Vtask_tb_top__DOT__check_mesi__67__cache)
            ? vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi
           [__Vtask_tb_top__DOT__check_mesi__67__index]
            : vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi
           [__Vtask_tb_top__DOT__check_mesi__67__index]);
    if (((IData)(vlSelf->tb_top__DOT__check_mesi__Vstatic__actual) 
         == (IData)(__Vtask_tb_top__DOT__check_mesi__67__expected))) {
        VL_WRITEF("  [PASS] Cache%0d index%0# state = %s\n",
                  32,__Vtask_tb_top__DOT__check_mesi__67__cache,
                  3,(IData)(__Vtask_tb_top__DOT__check_mesi__67__index),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__69__s 
                            = vlSelf->tb_top__DOT__check_mesi__Vstatic__actual;
                        __Vfunc_tb_top__DOT__mesi_name__69__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__69__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__69__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__69__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__69__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__69__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__69__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__69__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__69__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__69__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__69__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__69__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__69__Vfuncout).data());
    } else {
        VL_WRITEF("  [FAIL] Cache%0d index%0# state = %s  (expected %s)\n",
                  32,__Vtask_tb_top__DOT__check_mesi__67__cache,
                  3,(IData)(__Vtask_tb_top__DOT__check_mesi__67__index),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__70__s 
                            = vlSelf->tb_top__DOT__check_mesi__Vstatic__actual;
                        __Vfunc_tb_top__DOT__mesi_name__70__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__70__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__70__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__70__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__70__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__70__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__70__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__70__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__70__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__70__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__70__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__70__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__70__Vfuncout).data(),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__71__s 
                            = __Vtask_tb_top__DOT__check_mesi__67__expected;
                        __Vfunc_tb_top__DOT__mesi_name__71__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__71__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__71__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__71__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__71__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__71__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__71__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__71__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__71__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__71__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__71__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__71__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__71__Vfuncout).data());
        vlSelf->tb_top__DOT__errors = ((IData)(1U) 
                                       + vlSelf->tb_top__DOT__errors);
    }
    VL_WRITEF("  Bus BusInv count since test: %0d (expected 0 - no BusInv for E->M)\n",
              32,(vlSelf->tb_top__DOT__cnt_busInv - vlSelf->tb_top__DOT__bus_inv_before));
    co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_top.clk)", 
                                                       "tb/tb_mesi_system.v", 
                                                       377);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_top.clk)", 
                                                       "tb/tb_mesi_system.v", 
                                                       377);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_tb_top__DOT__separator__72__name[0U] = 
        Vtb_top__ConstPool__CONST_ha0f9cb69_0[0U];
    __Vtask_tb_top__DOT__separator__72__name[1U] = 
        Vtb_top__ConstPool__CONST_ha0f9cb69_0[1U];
    __Vtask_tb_top__DOT__separator__72__name[2U] = 
        Vtb_top__ConstPool__CONST_ha0f9cb69_0[2U];
    __Vtask_tb_top__DOT__separator__72__name[3U] = 
        Vtb_top__ConstPool__CONST_ha0f9cb69_0[3U];
    __Vtask_tb_top__DOT__separator__72__name[4U] = 
        Vtb_top__ConstPool__CONST_ha0f9cb69_0[4U];
    __Vtask_tb_top__DOT__separator__72__name[5U] = 
        Vtb_top__ConstPool__CONST_ha0f9cb69_0[5U];
    __Vtask_tb_top__DOT__separator__72__name[6U] = 
        Vtb_top__ConstPool__CONST_ha0f9cb69_0[6U];
    __Vtask_tb_top__DOT__separator__72__name[7U] = 
        Vtb_top__ConstPool__CONST_ha0f9cb69_0[7U];
    VL_WRITEF("\n============================================================\n %s\n============================================================\n",
              256,__Vtask_tb_top__DOT__separator__72__name.data());
    vlSelf->tb_top__DOT__bus_wb_before = vlSelf->tb_top__DOT__cnt_buswb;
    __Vtask_tb_top__DOT__cpu_write__73__wdata = 0xbeefcafeU;
    __Vtask_tb_top__DOT__cpu_write__73__addr = 0x30U;
    __Vtask_tb_top__DOT__cpu_write__73__core = 0U;
    vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout = 0U;
    if ((0U == __Vtask_tb_top__DOT__cpu_write__73__core)) {
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           188);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c0_req = 1U;
        vlSelf->tb_top__DOT__c0_we = 1U;
        vlSelf->tb_top__DOT__c0_addr = __Vtask_tb_top__DOT__cpu_write__73__addr;
        vlSelf->tb_top__DOT__c0_wdata = __Vtask_tb_top__DOT__cpu_write__73__wdata;
        co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           190);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        while (((~ (IData)(vlSelf->tb_top__DOT__c0_ack)) 
                & VL_GTS_III(32, 0x32U, vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout))) {
            co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_top.clk)", 
                                                               "tb/tb_mesi_system.v", 
                                                               192);
            vlSelf->__Vm_traceActivity[2U] = 1U;
            vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout 
                = ((IData)(1U) + vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout);
        }
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           195);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c0_req = 0U;
        vlSelf->tb_top__DOT__c0_we = 0U;
    } else {
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           198);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c1_req = 1U;
        vlSelf->tb_top__DOT__c1_we = 1U;
        vlSelf->tb_top__DOT__c1_addr = __Vtask_tb_top__DOT__cpu_write__73__addr;
        vlSelf->tb_top__DOT__c1_wdata = __Vtask_tb_top__DOT__cpu_write__73__wdata;
        co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           200);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        while (((~ (IData)(vlSelf->tb_top__DOT__c1_ack)) 
                & VL_GTS_III(32, 0x32U, vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout))) {
            co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_top.clk)", 
                                                               "tb/tb_mesi_system.v", 
                                                               202);
            vlSelf->__Vm_traceActivity[2U] = 1U;
            vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout 
                = ((IData)(1U) + vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout);
        }
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           205);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c1_req = 0U;
        vlSelf->tb_top__DOT__c1_we = 0U;
    }
    if (VL_UNLIKELY(VL_LTES_III(32, 0x32U, vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout))) {
        VL_WRITEF("  [WARN] cpu_write core%0d timed out!\n",
                  32,__Vtask_tb_top__DOT__cpu_write__73__core);
    }
    __Vtask_tb_top__DOT__check_mesi__74__expected = 3U;
    __Vfunc_tb_top__DOT__addr_to_index__75__a = 0x30U;
    __Vfunc_tb_top__DOT__addr_to_index__75__Vfuncout 
        = (7U & ((IData)(__Vfunc_tb_top__DOT__addr_to_index__75__a) 
                 >> 2U));
    __Vtask_tb_top__DOT__check_mesi__74__index = __Vfunc_tb_top__DOT__addr_to_index__75__Vfuncout;
    __Vtask_tb_top__DOT__check_mesi__74__cache = 0U;
    vlSelf->tb_top__DOT__check_mesi__Vstatic__actual 
        = ((0U == __Vtask_tb_top__DOT__check_mesi__74__cache)
            ? vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi
           [__Vtask_tb_top__DOT__check_mesi__74__index]
            : vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi
           [__Vtask_tb_top__DOT__check_mesi__74__index]);
    if (((IData)(vlSelf->tb_top__DOT__check_mesi__Vstatic__actual) 
         == (IData)(__Vtask_tb_top__DOT__check_mesi__74__expected))) {
        VL_WRITEF("  [PASS] Cache%0d index%0# state = %s\n",
                  32,__Vtask_tb_top__DOT__check_mesi__74__cache,
                  3,(IData)(__Vtask_tb_top__DOT__check_mesi__74__index),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__76__s 
                            = vlSelf->tb_top__DOT__check_mesi__Vstatic__actual;
                        __Vfunc_tb_top__DOT__mesi_name__76__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__76__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__76__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__76__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__76__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__76__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__76__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__76__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__76__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__76__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__76__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__76__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__76__Vfuncout).data());
    } else {
        VL_WRITEF("  [FAIL] Cache%0d index%0# state = %s  (expected %s)\n",
                  32,__Vtask_tb_top__DOT__check_mesi__74__cache,
                  3,(IData)(__Vtask_tb_top__DOT__check_mesi__74__index),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__77__s 
                            = vlSelf->tb_top__DOT__check_mesi__Vstatic__actual;
                        __Vfunc_tb_top__DOT__mesi_name__77__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__77__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__77__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__77__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__77__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__77__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__77__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__77__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__77__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__77__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__77__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__77__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__77__Vfuncout).data(),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__78__s 
                            = __Vtask_tb_top__DOT__check_mesi__74__expected;
                        __Vfunc_tb_top__DOT__mesi_name__78__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__78__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__78__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__78__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__78__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__78__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__78__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__78__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__78__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__78__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__78__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__78__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__78__Vfuncout).data());
        vlSelf->tb_top__DOT__errors = ((IData)(1U) 
                                       + vlSelf->tb_top__DOT__errors);
    }
    __Vtask_tb_top__DOT__cpu_read__79__addr = 0x10U;
    __Vtask_tb_top__DOT__cpu_read__79__core = 0U;
    vlSelf->tb_top__DOT__cpu_read__Vstatic__timeout = 0U;
    if ((0U == __Vtask_tb_top__DOT__cpu_read__79__core)) {
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           151);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c0_req = 1U;
        vlSelf->tb_top__DOT__c0_we = 0U;
        vlSelf->tb_top__DOT__c0_addr = __Vtask_tb_top__DOT__cpu_read__79__addr;
        co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           153);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        while (((~ (IData)(vlSelf->tb_top__DOT__c0_ack)) 
                & VL_GTS_III(32, 0x32U, vlSelf->tb_top__DOT__cpu_read__Vstatic__timeout))) {
            co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_top.clk)", 
                                                               "tb/tb_mesi_system.v", 
                                                               155);
            vlSelf->__Vm_traceActivity[2U] = 1U;
            vlSelf->tb_top__DOT__cpu_read__Vstatic__timeout 
                = ((IData)(1U) + vlSelf->tb_top__DOT__cpu_read__Vstatic__timeout);
        }
        __Vtask_tb_top__DOT__cpu_read__79__rdata = vlSelf->tb_top__DOT__c0_rdata;
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           159);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c0_req = 0U;
    } else {
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           162);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c1_req = 1U;
        vlSelf->tb_top__DOT__c1_we = 0U;
        vlSelf->tb_top__DOT__c1_addr = __Vtask_tb_top__DOT__cpu_read__79__addr;
        co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           164);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        while (((~ (IData)(vlSelf->tb_top__DOT__c1_ack)) 
                & VL_GTS_III(32, 0x32U, vlSelf->tb_top__DOT__cpu_read__Vstatic__timeout))) {
            co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_top.clk)", 
                                                               "tb/tb_mesi_system.v", 
                                                               166);
            vlSelf->__Vm_traceActivity[2U] = 1U;
            vlSelf->tb_top__DOT__cpu_read__Vstatic__timeout 
                = ((IData)(1U) + vlSelf->tb_top__DOT__cpu_read__Vstatic__timeout);
        }
        __Vtask_tb_top__DOT__cpu_read__79__rdata = vlSelf->tb_top__DOT__c1_rdata;
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           170);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c1_req = 0U;
    }
    if (VL_UNLIKELY(VL_LTES_III(32, 0x32U, vlSelf->tb_top__DOT__cpu_read__Vstatic__timeout))) {
        VL_WRITEF("  [WARN] cpu_read core%0d timed out!\n",
                  32,__Vtask_tb_top__DOT__cpu_read__79__core);
    }
    vlSelf->tb_top__DOT__rdata0 = __Vtask_tb_top__DOT__cpu_read__79__rdata;
    VL_WRITEF("  Bus BusWB count since test: %0d (expected 1)\n",
              32,(vlSelf->tb_top__DOT__cnt_buswb - vlSelf->tb_top__DOT__bus_wb_before));
    __Vtask_tb_top__DOT__check_data__80__label[0U] = 0x69656429U;
    __Vtask_tb_top__DOT__check_data__80__label[1U] = 0x7570706cU;
    __Vtask_tb_top__DOT__check_data__80__label[2U] = 0x65312073U;
    __Vtask_tb_top__DOT__check_data__80__label[3U] = 0x28436f72U;
    __Vtask_tb_top__DOT__check_data__80__expected = 0xdeadbeefU;
    __Vtask_tb_top__DOT__check_data__80__actual = vlSelf->tb_top__DOT__rdata0;
    if ((__Vtask_tb_top__DOT__check_data__80__actual 
         == __Vtask_tb_top__DOT__check_data__80__expected)) {
        VL_WRITEF("  [PASS] %s = 0x%08x\n",128,__Vtask_tb_top__DOT__check_data__80__label.data(),
                  32,__Vtask_tb_top__DOT__check_data__80__actual);
    } else {
        VL_WRITEF("  [FAIL] %s = 0x%08x  (expected 0x%08x)\n",
                  128,__Vtask_tb_top__DOT__check_data__80__label.data(),
                  32,__Vtask_tb_top__DOT__check_data__80__actual,
                  32,__Vtask_tb_top__DOT__check_data__80__expected);
        vlSelf->tb_top__DOT__errors = ((IData)(1U) 
                                       + vlSelf->tb_top__DOT__errors);
    }
    co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_top.clk)", 
                                                       "tb/tb_mesi_system.v", 
                                                       403);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_top.clk)", 
                                                       "tb/tb_mesi_system.v", 
                                                       403);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_tb_top__DOT__separator__81__name[0U] = 
        Vtb_top__ConstPool__CONST_hbb9be1b4_0[0U];
    __Vtask_tb_top__DOT__separator__81__name[1U] = 
        Vtb_top__ConstPool__CONST_hbb9be1b4_0[1U];
    __Vtask_tb_top__DOT__separator__81__name[2U] = 
        Vtb_top__ConstPool__CONST_hbb9be1b4_0[2U];
    __Vtask_tb_top__DOT__separator__81__name[3U] = 
        Vtb_top__ConstPool__CONST_hbb9be1b4_0[3U];
    __Vtask_tb_top__DOT__separator__81__name[4U] = 
        Vtb_top__ConstPool__CONST_hbb9be1b4_0[4U];
    __Vtask_tb_top__DOT__separator__81__name[5U] = 
        Vtb_top__ConstPool__CONST_hbb9be1b4_0[5U];
    __Vtask_tb_top__DOT__separator__81__name[6U] = 
        Vtb_top__ConstPool__CONST_hbb9be1b4_0[6U];
    __Vtask_tb_top__DOT__separator__81__name[7U] = 
        Vtb_top__ConstPool__CONST_hbb9be1b4_0[7U];
    VL_WRITEF("\n============================================================\n %s\n============================================================\n  Both cores write different words of address 0x40 alternately\n",
              256,__Vtask_tb_top__DOT__separator__81__name.data());
    __Vtask_tb_top__DOT__cpu_write__82__wdata = 0xa0000000U;
    __Vtask_tb_top__DOT__cpu_write__82__addr = 0x40U;
    __Vtask_tb_top__DOT__cpu_write__82__core = 0U;
    vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout = 0U;
    if ((0U == __Vtask_tb_top__DOT__cpu_write__82__core)) {
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           188);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c0_req = 1U;
        vlSelf->tb_top__DOT__c0_we = 1U;
        vlSelf->tb_top__DOT__c0_addr = __Vtask_tb_top__DOT__cpu_write__82__addr;
        vlSelf->tb_top__DOT__c0_wdata = __Vtask_tb_top__DOT__cpu_write__82__wdata;
        co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           190);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        while (((~ (IData)(vlSelf->tb_top__DOT__c0_ack)) 
                & VL_GTS_III(32, 0x32U, vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout))) {
            co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_top.clk)", 
                                                               "tb/tb_mesi_system.v", 
                                                               192);
            vlSelf->__Vm_traceActivity[2U] = 1U;
            vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout 
                = ((IData)(1U) + vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout);
        }
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           195);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c0_req = 0U;
        vlSelf->tb_top__DOT__c0_we = 0U;
    } else {
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           198);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c1_req = 1U;
        vlSelf->tb_top__DOT__c1_we = 1U;
        vlSelf->tb_top__DOT__c1_addr = __Vtask_tb_top__DOT__cpu_write__82__addr;
        vlSelf->tb_top__DOT__c1_wdata = __Vtask_tb_top__DOT__cpu_write__82__wdata;
        co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           200);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        while (((~ (IData)(vlSelf->tb_top__DOT__c1_ack)) 
                & VL_GTS_III(32, 0x32U, vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout))) {
            co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_top.clk)", 
                                                               "tb/tb_mesi_system.v", 
                                                               202);
            vlSelf->__Vm_traceActivity[2U] = 1U;
            vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout 
                = ((IData)(1U) + vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout);
        }
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           205);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c1_req = 0U;
        vlSelf->tb_top__DOT__c1_we = 0U;
    }
    if (VL_UNLIKELY(VL_LTES_III(32, 0x32U, vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout))) {
        VL_WRITEF("  [WARN] cpu_write core%0d timed out!\n",
                  32,__Vtask_tb_top__DOT__cpu_write__82__core);
    }
    __Vtask_tb_top__DOT__check_mesi__83__expected = 3U;
    __Vfunc_tb_top__DOT__addr_to_index__84__a = 0x40U;
    __Vfunc_tb_top__DOT__addr_to_index__84__Vfuncout 
        = (7U & ((IData)(__Vfunc_tb_top__DOT__addr_to_index__84__a) 
                 >> 2U));
    __Vtask_tb_top__DOT__check_mesi__83__index = __Vfunc_tb_top__DOT__addr_to_index__84__Vfuncout;
    __Vtask_tb_top__DOT__check_mesi__83__cache = 0U;
    vlSelf->tb_top__DOT__check_mesi__Vstatic__actual 
        = ((0U == __Vtask_tb_top__DOT__check_mesi__83__cache)
            ? vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi
           [__Vtask_tb_top__DOT__check_mesi__83__index]
            : vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi
           [__Vtask_tb_top__DOT__check_mesi__83__index]);
    if (((IData)(vlSelf->tb_top__DOT__check_mesi__Vstatic__actual) 
         == (IData)(__Vtask_tb_top__DOT__check_mesi__83__expected))) {
        VL_WRITEF("  [PASS] Cache%0d index%0# state = %s\n",
                  32,__Vtask_tb_top__DOT__check_mesi__83__cache,
                  3,(IData)(__Vtask_tb_top__DOT__check_mesi__83__index),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__85__s 
                            = vlSelf->tb_top__DOT__check_mesi__Vstatic__actual;
                        __Vfunc_tb_top__DOT__mesi_name__85__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__85__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__85__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__85__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__85__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__85__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__85__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__85__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__85__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__85__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__85__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__85__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__85__Vfuncout).data());
    } else {
        VL_WRITEF("  [FAIL] Cache%0d index%0# state = %s  (expected %s)\n",
                  32,__Vtask_tb_top__DOT__check_mesi__83__cache,
                  3,(IData)(__Vtask_tb_top__DOT__check_mesi__83__index),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__86__s 
                            = vlSelf->tb_top__DOT__check_mesi__Vstatic__actual;
                        __Vfunc_tb_top__DOT__mesi_name__86__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__86__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__86__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__86__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__86__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__86__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__86__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__86__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__86__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__86__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__86__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__86__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__86__Vfuncout).data(),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__87__s 
                            = __Vtask_tb_top__DOT__check_mesi__83__expected;
                        __Vfunc_tb_top__DOT__mesi_name__87__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__87__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__87__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__87__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__87__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__87__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__87__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__87__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__87__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__87__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__87__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__87__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__87__Vfuncout).data());
        vlSelf->tb_top__DOT__errors = ((IData)(1U) 
                                       + vlSelf->tb_top__DOT__errors);
    }
    __Vtask_tb_top__DOT__check_mesi__88__expected = 0U;
    __Vfunc_tb_top__DOT__addr_to_index__89__a = 0x40U;
    __Vfunc_tb_top__DOT__addr_to_index__89__Vfuncout 
        = (7U & ((IData)(__Vfunc_tb_top__DOT__addr_to_index__89__a) 
                 >> 2U));
    __Vtask_tb_top__DOT__check_mesi__88__index = __Vfunc_tb_top__DOT__addr_to_index__89__Vfuncout;
    __Vtask_tb_top__DOT__check_mesi__88__cache = 1U;
    vlSelf->tb_top__DOT__check_mesi__Vstatic__actual 
        = ((0U == __Vtask_tb_top__DOT__check_mesi__88__cache)
            ? vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi
           [__Vtask_tb_top__DOT__check_mesi__88__index]
            : vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi
           [__Vtask_tb_top__DOT__check_mesi__88__index]);
    if (((IData)(vlSelf->tb_top__DOT__check_mesi__Vstatic__actual) 
         == (IData)(__Vtask_tb_top__DOT__check_mesi__88__expected))) {
        VL_WRITEF("  [PASS] Cache%0d index%0# state = %s\n",
                  32,__Vtask_tb_top__DOT__check_mesi__88__cache,
                  3,(IData)(__Vtask_tb_top__DOT__check_mesi__88__index),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__90__s 
                            = vlSelf->tb_top__DOT__check_mesi__Vstatic__actual;
                        __Vfunc_tb_top__DOT__mesi_name__90__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__90__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__90__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__90__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__90__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__90__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__90__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__90__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__90__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__90__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__90__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__90__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__90__Vfuncout).data());
    } else {
        VL_WRITEF("  [FAIL] Cache%0d index%0# state = %s  (expected %s)\n",
                  32,__Vtask_tb_top__DOT__check_mesi__88__cache,
                  3,(IData)(__Vtask_tb_top__DOT__check_mesi__88__index),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__91__s 
                            = vlSelf->tb_top__DOT__check_mesi__Vstatic__actual;
                        __Vfunc_tb_top__DOT__mesi_name__91__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__91__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__91__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__91__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__91__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__91__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__91__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__91__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__91__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__91__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__91__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__91__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__91__Vfuncout).data(),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__92__s 
                            = __Vtask_tb_top__DOT__check_mesi__88__expected;
                        __Vfunc_tb_top__DOT__mesi_name__92__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__92__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__92__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__92__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__92__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__92__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__92__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__92__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__92__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__92__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__92__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__92__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__92__Vfuncout).data());
        vlSelf->tb_top__DOT__errors = ((IData)(1U) 
                                       + vlSelf->tb_top__DOT__errors);
    }
    __Vtask_tb_top__DOT__cpu_write__93__wdata = 0xb0000000U;
    __Vtask_tb_top__DOT__cpu_write__93__addr = 0x44U;
    __Vtask_tb_top__DOT__cpu_write__93__core = 1U;
    vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout = 0U;
    if ((0U == __Vtask_tb_top__DOT__cpu_write__93__core)) {
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           188);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c0_req = 1U;
        vlSelf->tb_top__DOT__c0_we = 1U;
        vlSelf->tb_top__DOT__c0_addr = __Vtask_tb_top__DOT__cpu_write__93__addr;
        vlSelf->tb_top__DOT__c0_wdata = __Vtask_tb_top__DOT__cpu_write__93__wdata;
        co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           190);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        while (((~ (IData)(vlSelf->tb_top__DOT__c0_ack)) 
                & VL_GTS_III(32, 0x32U, vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout))) {
            co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_top.clk)", 
                                                               "tb/tb_mesi_system.v", 
                                                               192);
            vlSelf->__Vm_traceActivity[2U] = 1U;
            vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout 
                = ((IData)(1U) + vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout);
        }
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           195);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c0_req = 0U;
        vlSelf->tb_top__DOT__c0_we = 0U;
    } else {
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           198);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c1_req = 1U;
        vlSelf->tb_top__DOT__c1_we = 1U;
        vlSelf->tb_top__DOT__c1_addr = __Vtask_tb_top__DOT__cpu_write__93__addr;
        vlSelf->tb_top__DOT__c1_wdata = __Vtask_tb_top__DOT__cpu_write__93__wdata;
        co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           200);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        while (((~ (IData)(vlSelf->tb_top__DOT__c1_ack)) 
                & VL_GTS_III(32, 0x32U, vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout))) {
            co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_top.clk)", 
                                                               "tb/tb_mesi_system.v", 
                                                               202);
            vlSelf->__Vm_traceActivity[2U] = 1U;
            vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout 
                = ((IData)(1U) + vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout);
        }
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           205);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c1_req = 0U;
        vlSelf->tb_top__DOT__c1_we = 0U;
    }
    if (VL_UNLIKELY(VL_LTES_III(32, 0x32U, vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout))) {
        VL_WRITEF("  [WARN] cpu_write core%0d timed out!\n",
                  32,__Vtask_tb_top__DOT__cpu_write__93__core);
    }
    __Vtask_tb_top__DOT__check_mesi__94__expected = 3U;
    __Vfunc_tb_top__DOT__addr_to_index__95__a = 0x44U;
    __Vfunc_tb_top__DOT__addr_to_index__95__Vfuncout 
        = (7U & ((IData)(__Vfunc_tb_top__DOT__addr_to_index__95__a) 
                 >> 2U));
    __Vtask_tb_top__DOT__check_mesi__94__index = __Vfunc_tb_top__DOT__addr_to_index__95__Vfuncout;
    __Vtask_tb_top__DOT__check_mesi__94__cache = 1U;
    vlSelf->tb_top__DOT__check_mesi__Vstatic__actual 
        = ((0U == __Vtask_tb_top__DOT__check_mesi__94__cache)
            ? vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi
           [__Vtask_tb_top__DOT__check_mesi__94__index]
            : vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi
           [__Vtask_tb_top__DOT__check_mesi__94__index]);
    if (((IData)(vlSelf->tb_top__DOT__check_mesi__Vstatic__actual) 
         == (IData)(__Vtask_tb_top__DOT__check_mesi__94__expected))) {
        VL_WRITEF("  [PASS] Cache%0d index%0# state = %s\n",
                  32,__Vtask_tb_top__DOT__check_mesi__94__cache,
                  3,(IData)(__Vtask_tb_top__DOT__check_mesi__94__index),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__96__s 
                            = vlSelf->tb_top__DOT__check_mesi__Vstatic__actual;
                        __Vfunc_tb_top__DOT__mesi_name__96__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__96__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__96__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__96__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__96__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__96__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__96__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__96__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__96__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__96__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__96__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__96__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__96__Vfuncout).data());
    } else {
        VL_WRITEF("  [FAIL] Cache%0d index%0# state = %s  (expected %s)\n",
                  32,__Vtask_tb_top__DOT__check_mesi__94__cache,
                  3,(IData)(__Vtask_tb_top__DOT__check_mesi__94__index),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__97__s 
                            = vlSelf->tb_top__DOT__check_mesi__Vstatic__actual;
                        __Vfunc_tb_top__DOT__mesi_name__97__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__97__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__97__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__97__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__97__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__97__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__97__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__97__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__97__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__97__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__97__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__97__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__97__Vfuncout).data(),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__98__s 
                            = __Vtask_tb_top__DOT__check_mesi__94__expected;
                        __Vfunc_tb_top__DOT__mesi_name__98__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__98__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__98__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__98__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__98__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__98__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__98__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__98__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__98__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__98__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__98__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__98__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__98__Vfuncout).data());
        vlSelf->tb_top__DOT__errors = ((IData)(1U) 
                                       + vlSelf->tb_top__DOT__errors);
    }
    __Vtask_tb_top__DOT__check_mesi__99__expected = 0U;
    __Vfunc_tb_top__DOT__addr_to_index__100__a = 0x44U;
    __Vfunc_tb_top__DOT__addr_to_index__100__Vfuncout 
        = (7U & ((IData)(__Vfunc_tb_top__DOT__addr_to_index__100__a) 
                 >> 2U));
    __Vtask_tb_top__DOT__check_mesi__99__index = __Vfunc_tb_top__DOT__addr_to_index__100__Vfuncout;
    __Vtask_tb_top__DOT__check_mesi__99__cache = 0U;
    vlSelf->tb_top__DOT__check_mesi__Vstatic__actual 
        = ((0U == __Vtask_tb_top__DOT__check_mesi__99__cache)
            ? vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi
           [__Vtask_tb_top__DOT__check_mesi__99__index]
            : vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi
           [__Vtask_tb_top__DOT__check_mesi__99__index]);
    if (((IData)(vlSelf->tb_top__DOT__check_mesi__Vstatic__actual) 
         == (IData)(__Vtask_tb_top__DOT__check_mesi__99__expected))) {
        VL_WRITEF("  [PASS] Cache%0d index%0# state = %s\n",
                  32,__Vtask_tb_top__DOT__check_mesi__99__cache,
                  3,(IData)(__Vtask_tb_top__DOT__check_mesi__99__index),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__101__s 
                            = vlSelf->tb_top__DOT__check_mesi__Vstatic__actual;
                        __Vfunc_tb_top__DOT__mesi_name__101__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__101__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__101__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__101__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__101__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__101__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__101__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__101__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__101__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__101__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__101__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__101__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__101__Vfuncout).data());
    } else {
        VL_WRITEF("  [FAIL] Cache%0d index%0# state = %s  (expected %s)\n",
                  32,__Vtask_tb_top__DOT__check_mesi__99__cache,
                  3,(IData)(__Vtask_tb_top__DOT__check_mesi__99__index),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__102__s 
                            = vlSelf->tb_top__DOT__check_mesi__Vstatic__actual;
                        __Vfunc_tb_top__DOT__mesi_name__102__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__102__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__102__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__102__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__102__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__102__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__102__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__102__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__102__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__102__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__102__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__102__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__102__Vfuncout).data(),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__103__s 
                            = __Vtask_tb_top__DOT__check_mesi__99__expected;
                        __Vfunc_tb_top__DOT__mesi_name__103__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__103__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__103__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__103__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__103__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__103__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__103__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__103__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__103__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__103__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__103__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__103__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__103__Vfuncout).data());
        vlSelf->tb_top__DOT__errors = ((IData)(1U) 
                                       + vlSelf->tb_top__DOT__errors);
    }
    VL_WRITEF("  Iteration 0: coherence maintained\n");
    co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_top.clk)", 
                                                       "tb/tb_mesi_system.v", 
                                                       426);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_top.clk)", 
                                                       "tb/tb_mesi_system.v", 
                                                       426);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb_top__DOT__stress__DOT__iter = 1U;
    __Vtask_tb_top__DOT__cpu_write__82__wdata = 0xa0000001U;
    __Vtask_tb_top__DOT__cpu_write__82__addr = 0x40U;
    __Vtask_tb_top__DOT__cpu_write__82__core = 0U;
    vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout = 0U;
    if ((0U == __Vtask_tb_top__DOT__cpu_write__82__core)) {
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           188);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c0_req = 1U;
        vlSelf->tb_top__DOT__c0_we = 1U;
        vlSelf->tb_top__DOT__c0_addr = __Vtask_tb_top__DOT__cpu_write__82__addr;
        vlSelf->tb_top__DOT__c0_wdata = __Vtask_tb_top__DOT__cpu_write__82__wdata;
        co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           190);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        while (((~ (IData)(vlSelf->tb_top__DOT__c0_ack)) 
                & VL_GTS_III(32, 0x32U, vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout))) {
            co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_top.clk)", 
                                                               "tb/tb_mesi_system.v", 
                                                               192);
            vlSelf->__Vm_traceActivity[2U] = 1U;
            vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout 
                = ((IData)(1U) + vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout);
        }
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           195);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c0_req = 0U;
        vlSelf->tb_top__DOT__c0_we = 0U;
    } else {
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           198);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c1_req = 1U;
        vlSelf->tb_top__DOT__c1_we = 1U;
        vlSelf->tb_top__DOT__c1_addr = __Vtask_tb_top__DOT__cpu_write__82__addr;
        vlSelf->tb_top__DOT__c1_wdata = __Vtask_tb_top__DOT__cpu_write__82__wdata;
        co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           200);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        while (((~ (IData)(vlSelf->tb_top__DOT__c1_ack)) 
                & VL_GTS_III(32, 0x32U, vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout))) {
            co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_top.clk)", 
                                                               "tb/tb_mesi_system.v", 
                                                               202);
            vlSelf->__Vm_traceActivity[2U] = 1U;
            vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout 
                = ((IData)(1U) + vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout);
        }
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           205);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c1_req = 0U;
        vlSelf->tb_top__DOT__c1_we = 0U;
    }
    if (VL_UNLIKELY(VL_LTES_III(32, 0x32U, vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout))) {
        VL_WRITEF("  [WARN] cpu_write core%0d timed out!\n",
                  32,__Vtask_tb_top__DOT__cpu_write__82__core);
    }
    __Vtask_tb_top__DOT__check_mesi__83__expected = 3U;
    __Vfunc_tb_top__DOT__addr_to_index__84__a = 0x40U;
    __Vfunc_tb_top__DOT__addr_to_index__84__Vfuncout 
        = (7U & ((IData)(__Vfunc_tb_top__DOT__addr_to_index__84__a) 
                 >> 2U));
    __Vtask_tb_top__DOT__check_mesi__83__index = __Vfunc_tb_top__DOT__addr_to_index__84__Vfuncout;
    __Vtask_tb_top__DOT__check_mesi__83__cache = 0U;
    vlSelf->tb_top__DOT__check_mesi__Vstatic__actual 
        = ((0U == __Vtask_tb_top__DOT__check_mesi__83__cache)
            ? vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi
           [__Vtask_tb_top__DOT__check_mesi__83__index]
            : vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi
           [__Vtask_tb_top__DOT__check_mesi__83__index]);
    if (((IData)(vlSelf->tb_top__DOT__check_mesi__Vstatic__actual) 
         == (IData)(__Vtask_tb_top__DOT__check_mesi__83__expected))) {
        VL_WRITEF("  [PASS] Cache%0d index%0# state = %s\n",
                  32,__Vtask_tb_top__DOT__check_mesi__83__cache,
                  3,(IData)(__Vtask_tb_top__DOT__check_mesi__83__index),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__85__s 
                            = vlSelf->tb_top__DOT__check_mesi__Vstatic__actual;
                        __Vfunc_tb_top__DOT__mesi_name__85__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__85__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__85__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__85__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__85__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__85__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__85__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__85__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__85__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__85__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__85__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__85__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__85__Vfuncout).data());
    } else {
        VL_WRITEF("  [FAIL] Cache%0d index%0# state = %s  (expected %s)\n",
                  32,__Vtask_tb_top__DOT__check_mesi__83__cache,
                  3,(IData)(__Vtask_tb_top__DOT__check_mesi__83__index),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__86__s 
                            = vlSelf->tb_top__DOT__check_mesi__Vstatic__actual;
                        __Vfunc_tb_top__DOT__mesi_name__86__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__86__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__86__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__86__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__86__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__86__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__86__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__86__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__86__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__86__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__86__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__86__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__86__Vfuncout).data(),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__87__s 
                            = __Vtask_tb_top__DOT__check_mesi__83__expected;
                        __Vfunc_tb_top__DOT__mesi_name__87__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__87__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__87__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__87__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__87__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__87__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__87__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__87__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__87__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__87__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__87__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__87__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__87__Vfuncout).data());
        vlSelf->tb_top__DOT__errors = ((IData)(1U) 
                                       + vlSelf->tb_top__DOT__errors);
    }
    __Vtask_tb_top__DOT__check_mesi__88__expected = 0U;
    __Vfunc_tb_top__DOT__addr_to_index__89__a = 0x40U;
    __Vfunc_tb_top__DOT__addr_to_index__89__Vfuncout 
        = (7U & ((IData)(__Vfunc_tb_top__DOT__addr_to_index__89__a) 
                 >> 2U));
    __Vtask_tb_top__DOT__check_mesi__88__index = __Vfunc_tb_top__DOT__addr_to_index__89__Vfuncout;
    __Vtask_tb_top__DOT__check_mesi__88__cache = 1U;
    vlSelf->tb_top__DOT__check_mesi__Vstatic__actual 
        = ((0U == __Vtask_tb_top__DOT__check_mesi__88__cache)
            ? vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi
           [__Vtask_tb_top__DOT__check_mesi__88__index]
            : vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi
           [__Vtask_tb_top__DOT__check_mesi__88__index]);
    if (((IData)(vlSelf->tb_top__DOT__check_mesi__Vstatic__actual) 
         == (IData)(__Vtask_tb_top__DOT__check_mesi__88__expected))) {
        VL_WRITEF("  [PASS] Cache%0d index%0# state = %s\n",
                  32,__Vtask_tb_top__DOT__check_mesi__88__cache,
                  3,(IData)(__Vtask_tb_top__DOT__check_mesi__88__index),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__90__s 
                            = vlSelf->tb_top__DOT__check_mesi__Vstatic__actual;
                        __Vfunc_tb_top__DOT__mesi_name__90__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__90__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__90__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__90__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__90__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__90__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__90__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__90__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__90__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__90__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__90__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__90__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__90__Vfuncout).data());
    } else {
        VL_WRITEF("  [FAIL] Cache%0d index%0# state = %s  (expected %s)\n",
                  32,__Vtask_tb_top__DOT__check_mesi__88__cache,
                  3,(IData)(__Vtask_tb_top__DOT__check_mesi__88__index),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__91__s 
                            = vlSelf->tb_top__DOT__check_mesi__Vstatic__actual;
                        __Vfunc_tb_top__DOT__mesi_name__91__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__91__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__91__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__91__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__91__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__91__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__91__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__91__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__91__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__91__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__91__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__91__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__91__Vfuncout).data(),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__92__s 
                            = __Vtask_tb_top__DOT__check_mesi__88__expected;
                        __Vfunc_tb_top__DOT__mesi_name__92__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__92__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__92__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__92__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__92__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__92__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__92__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__92__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__92__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__92__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__92__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__92__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__92__Vfuncout).data());
        vlSelf->tb_top__DOT__errors = ((IData)(1U) 
                                       + vlSelf->tb_top__DOT__errors);
    }
    __Vtask_tb_top__DOT__cpu_write__93__wdata = 0xb0000001U;
    __Vtask_tb_top__DOT__cpu_write__93__addr = 0x44U;
    __Vtask_tb_top__DOT__cpu_write__93__core = 1U;
    vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout = 0U;
    if ((0U == __Vtask_tb_top__DOT__cpu_write__93__core)) {
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           188);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c0_req = 1U;
        vlSelf->tb_top__DOT__c0_we = 1U;
        vlSelf->tb_top__DOT__c0_addr = __Vtask_tb_top__DOT__cpu_write__93__addr;
        vlSelf->tb_top__DOT__c0_wdata = __Vtask_tb_top__DOT__cpu_write__93__wdata;
        co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           190);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        while (((~ (IData)(vlSelf->tb_top__DOT__c0_ack)) 
                & VL_GTS_III(32, 0x32U, vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout))) {
            co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_top.clk)", 
                                                               "tb/tb_mesi_system.v", 
                                                               192);
            vlSelf->__Vm_traceActivity[2U] = 1U;
            vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout 
                = ((IData)(1U) + vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout);
        }
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           195);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c0_req = 0U;
        vlSelf->tb_top__DOT__c0_we = 0U;
    } else {
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           198);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c1_req = 1U;
        vlSelf->tb_top__DOT__c1_we = 1U;
        vlSelf->tb_top__DOT__c1_addr = __Vtask_tb_top__DOT__cpu_write__93__addr;
        vlSelf->tb_top__DOT__c1_wdata = __Vtask_tb_top__DOT__cpu_write__93__wdata;
        co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           200);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        while (((~ (IData)(vlSelf->tb_top__DOT__c1_ack)) 
                & VL_GTS_III(32, 0x32U, vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout))) {
            co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_top.clk)", 
                                                               "tb/tb_mesi_system.v", 
                                                               202);
            vlSelf->__Vm_traceActivity[2U] = 1U;
            vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout 
                = ((IData)(1U) + vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout);
        }
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           205);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c1_req = 0U;
        vlSelf->tb_top__DOT__c1_we = 0U;
    }
    if (VL_UNLIKELY(VL_LTES_III(32, 0x32U, vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout))) {
        VL_WRITEF("  [WARN] cpu_write core%0d timed out!\n",
                  32,__Vtask_tb_top__DOT__cpu_write__93__core);
    }
    __Vtask_tb_top__DOT__check_mesi__94__expected = 3U;
    __Vfunc_tb_top__DOT__addr_to_index__95__a = 0x44U;
    __Vfunc_tb_top__DOT__addr_to_index__95__Vfuncout 
        = (7U & ((IData)(__Vfunc_tb_top__DOT__addr_to_index__95__a) 
                 >> 2U));
    __Vtask_tb_top__DOT__check_mesi__94__index = __Vfunc_tb_top__DOT__addr_to_index__95__Vfuncout;
    __Vtask_tb_top__DOT__check_mesi__94__cache = 1U;
    vlSelf->tb_top__DOT__check_mesi__Vstatic__actual 
        = ((0U == __Vtask_tb_top__DOT__check_mesi__94__cache)
            ? vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi
           [__Vtask_tb_top__DOT__check_mesi__94__index]
            : vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi
           [__Vtask_tb_top__DOT__check_mesi__94__index]);
    if (((IData)(vlSelf->tb_top__DOT__check_mesi__Vstatic__actual) 
         == (IData)(__Vtask_tb_top__DOT__check_mesi__94__expected))) {
        VL_WRITEF("  [PASS] Cache%0d index%0# state = %s\n",
                  32,__Vtask_tb_top__DOT__check_mesi__94__cache,
                  3,(IData)(__Vtask_tb_top__DOT__check_mesi__94__index),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__96__s 
                            = vlSelf->tb_top__DOT__check_mesi__Vstatic__actual;
                        __Vfunc_tb_top__DOT__mesi_name__96__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__96__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__96__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__96__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__96__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__96__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__96__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__96__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__96__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__96__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__96__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__96__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__96__Vfuncout).data());
    } else {
        VL_WRITEF("  [FAIL] Cache%0d index%0# state = %s  (expected %s)\n",
                  32,__Vtask_tb_top__DOT__check_mesi__94__cache,
                  3,(IData)(__Vtask_tb_top__DOT__check_mesi__94__index),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__97__s 
                            = vlSelf->tb_top__DOT__check_mesi__Vstatic__actual;
                        __Vfunc_tb_top__DOT__mesi_name__97__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__97__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__97__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__97__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__97__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__97__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__97__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__97__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__97__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__97__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__97__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__97__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__97__Vfuncout).data(),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__98__s 
                            = __Vtask_tb_top__DOT__check_mesi__94__expected;
                        __Vfunc_tb_top__DOT__mesi_name__98__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__98__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__98__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__98__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__98__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__98__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__98__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__98__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__98__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__98__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__98__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__98__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__98__Vfuncout).data());
        vlSelf->tb_top__DOT__errors = ((IData)(1U) 
                                       + vlSelf->tb_top__DOT__errors);
    }
    __Vtask_tb_top__DOT__check_mesi__99__expected = 0U;
    __Vfunc_tb_top__DOT__addr_to_index__100__a = 0x44U;
    __Vfunc_tb_top__DOT__addr_to_index__100__Vfuncout 
        = (7U & ((IData)(__Vfunc_tb_top__DOT__addr_to_index__100__a) 
                 >> 2U));
    __Vtask_tb_top__DOT__check_mesi__99__index = __Vfunc_tb_top__DOT__addr_to_index__100__Vfuncout;
    __Vtask_tb_top__DOT__check_mesi__99__cache = 0U;
    vlSelf->tb_top__DOT__check_mesi__Vstatic__actual 
        = ((0U == __Vtask_tb_top__DOT__check_mesi__99__cache)
            ? vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi
           [__Vtask_tb_top__DOT__check_mesi__99__index]
            : vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi
           [__Vtask_tb_top__DOT__check_mesi__99__index]);
    if (((IData)(vlSelf->tb_top__DOT__check_mesi__Vstatic__actual) 
         == (IData)(__Vtask_tb_top__DOT__check_mesi__99__expected))) {
        VL_WRITEF("  [PASS] Cache%0d index%0# state = %s\n",
                  32,__Vtask_tb_top__DOT__check_mesi__99__cache,
                  3,(IData)(__Vtask_tb_top__DOT__check_mesi__99__index),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__101__s 
                            = vlSelf->tb_top__DOT__check_mesi__Vstatic__actual;
                        __Vfunc_tb_top__DOT__mesi_name__101__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__101__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__101__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__101__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__101__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__101__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__101__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__101__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__101__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__101__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__101__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__101__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__101__Vfuncout).data());
    } else {
        VL_WRITEF("  [FAIL] Cache%0d index%0# state = %s  (expected %s)\n",
                  32,__Vtask_tb_top__DOT__check_mesi__99__cache,
                  3,(IData)(__Vtask_tb_top__DOT__check_mesi__99__index),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__102__s 
                            = vlSelf->tb_top__DOT__check_mesi__Vstatic__actual;
                        __Vfunc_tb_top__DOT__mesi_name__102__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__102__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__102__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__102__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__102__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__102__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__102__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__102__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__102__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__102__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__102__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__102__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__102__Vfuncout).data(),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__103__s 
                            = __Vtask_tb_top__DOT__check_mesi__99__expected;
                        __Vfunc_tb_top__DOT__mesi_name__103__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__103__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__103__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__103__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__103__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__103__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__103__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__103__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__103__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__103__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__103__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__103__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__103__Vfuncout).data());
        vlSelf->tb_top__DOT__errors = ((IData)(1U) 
                                       + vlSelf->tb_top__DOT__errors);
    }
    VL_WRITEF("  Iteration 1: coherence maintained\n");
    co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_top.clk)", 
                                                       "tb/tb_mesi_system.v", 
                                                       426);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_top.clk)", 
                                                       "tb/tb_mesi_system.v", 
                                                       426);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb_top__DOT__stress__DOT__iter = 2U;
    __Vtask_tb_top__DOT__cpu_write__82__wdata = 0xa0000002U;
    __Vtask_tb_top__DOT__cpu_write__82__addr = 0x40U;
    __Vtask_tb_top__DOT__cpu_write__82__core = 0U;
    vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout = 0U;
    if ((0U == __Vtask_tb_top__DOT__cpu_write__82__core)) {
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           188);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c0_req = 1U;
        vlSelf->tb_top__DOT__c0_we = 1U;
        vlSelf->tb_top__DOT__c0_addr = __Vtask_tb_top__DOT__cpu_write__82__addr;
        vlSelf->tb_top__DOT__c0_wdata = __Vtask_tb_top__DOT__cpu_write__82__wdata;
        co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           190);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        while (((~ (IData)(vlSelf->tb_top__DOT__c0_ack)) 
                & VL_GTS_III(32, 0x32U, vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout))) {
            co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_top.clk)", 
                                                               "tb/tb_mesi_system.v", 
                                                               192);
            vlSelf->__Vm_traceActivity[2U] = 1U;
            vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout 
                = ((IData)(1U) + vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout);
        }
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           195);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c0_req = 0U;
        vlSelf->tb_top__DOT__c0_we = 0U;
    } else {
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           198);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c1_req = 1U;
        vlSelf->tb_top__DOT__c1_we = 1U;
        vlSelf->tb_top__DOT__c1_addr = __Vtask_tb_top__DOT__cpu_write__82__addr;
        vlSelf->tb_top__DOT__c1_wdata = __Vtask_tb_top__DOT__cpu_write__82__wdata;
        co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           200);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        while (((~ (IData)(vlSelf->tb_top__DOT__c1_ack)) 
                & VL_GTS_III(32, 0x32U, vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout))) {
            co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_top.clk)", 
                                                               "tb/tb_mesi_system.v", 
                                                               202);
            vlSelf->__Vm_traceActivity[2U] = 1U;
            vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout 
                = ((IData)(1U) + vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout);
        }
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           205);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c1_req = 0U;
        vlSelf->tb_top__DOT__c1_we = 0U;
    }
    if (VL_UNLIKELY(VL_LTES_III(32, 0x32U, vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout))) {
        VL_WRITEF("  [WARN] cpu_write core%0d timed out!\n",
                  32,__Vtask_tb_top__DOT__cpu_write__82__core);
    }
    __Vtask_tb_top__DOT__check_mesi__83__expected = 3U;
    __Vfunc_tb_top__DOT__addr_to_index__84__a = 0x40U;
    __Vfunc_tb_top__DOT__addr_to_index__84__Vfuncout 
        = (7U & ((IData)(__Vfunc_tb_top__DOT__addr_to_index__84__a) 
                 >> 2U));
    __Vtask_tb_top__DOT__check_mesi__83__index = __Vfunc_tb_top__DOT__addr_to_index__84__Vfuncout;
    __Vtask_tb_top__DOT__check_mesi__83__cache = 0U;
    vlSelf->tb_top__DOT__check_mesi__Vstatic__actual 
        = ((0U == __Vtask_tb_top__DOT__check_mesi__83__cache)
            ? vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi
           [__Vtask_tb_top__DOT__check_mesi__83__index]
            : vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi
           [__Vtask_tb_top__DOT__check_mesi__83__index]);
    if (((IData)(vlSelf->tb_top__DOT__check_mesi__Vstatic__actual) 
         == (IData)(__Vtask_tb_top__DOT__check_mesi__83__expected))) {
        VL_WRITEF("  [PASS] Cache%0d index%0# state = %s\n",
                  32,__Vtask_tb_top__DOT__check_mesi__83__cache,
                  3,(IData)(__Vtask_tb_top__DOT__check_mesi__83__index),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__85__s 
                            = vlSelf->tb_top__DOT__check_mesi__Vstatic__actual;
                        __Vfunc_tb_top__DOT__mesi_name__85__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__85__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__85__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__85__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__85__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__85__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__85__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__85__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__85__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__85__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__85__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__85__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__85__Vfuncout).data());
    } else {
        VL_WRITEF("  [FAIL] Cache%0d index%0# state = %s  (expected %s)\n",
                  32,__Vtask_tb_top__DOT__check_mesi__83__cache,
                  3,(IData)(__Vtask_tb_top__DOT__check_mesi__83__index),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__86__s 
                            = vlSelf->tb_top__DOT__check_mesi__Vstatic__actual;
                        __Vfunc_tb_top__DOT__mesi_name__86__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__86__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__86__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__86__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__86__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__86__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__86__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__86__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__86__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__86__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__86__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__86__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__86__Vfuncout).data(),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__87__s 
                            = __Vtask_tb_top__DOT__check_mesi__83__expected;
                        __Vfunc_tb_top__DOT__mesi_name__87__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__87__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__87__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__87__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__87__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__87__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__87__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__87__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__87__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__87__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__87__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__87__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__87__Vfuncout).data());
        vlSelf->tb_top__DOT__errors = ((IData)(1U) 
                                       + vlSelf->tb_top__DOT__errors);
    }
    __Vtask_tb_top__DOT__check_mesi__88__expected = 0U;
    __Vfunc_tb_top__DOT__addr_to_index__89__a = 0x40U;
    __Vfunc_tb_top__DOT__addr_to_index__89__Vfuncout 
        = (7U & ((IData)(__Vfunc_tb_top__DOT__addr_to_index__89__a) 
                 >> 2U));
    __Vtask_tb_top__DOT__check_mesi__88__index = __Vfunc_tb_top__DOT__addr_to_index__89__Vfuncout;
    __Vtask_tb_top__DOT__check_mesi__88__cache = 1U;
    vlSelf->tb_top__DOT__check_mesi__Vstatic__actual 
        = ((0U == __Vtask_tb_top__DOT__check_mesi__88__cache)
            ? vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi
           [__Vtask_tb_top__DOT__check_mesi__88__index]
            : vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi
           [__Vtask_tb_top__DOT__check_mesi__88__index]);
    if (((IData)(vlSelf->tb_top__DOT__check_mesi__Vstatic__actual) 
         == (IData)(__Vtask_tb_top__DOT__check_mesi__88__expected))) {
        VL_WRITEF("  [PASS] Cache%0d index%0# state = %s\n",
                  32,__Vtask_tb_top__DOT__check_mesi__88__cache,
                  3,(IData)(__Vtask_tb_top__DOT__check_mesi__88__index),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__90__s 
                            = vlSelf->tb_top__DOT__check_mesi__Vstatic__actual;
                        __Vfunc_tb_top__DOT__mesi_name__90__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__90__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__90__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__90__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__90__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__90__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__90__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__90__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__90__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__90__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__90__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__90__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__90__Vfuncout).data());
    } else {
        VL_WRITEF("  [FAIL] Cache%0d index%0# state = %s  (expected %s)\n",
                  32,__Vtask_tb_top__DOT__check_mesi__88__cache,
                  3,(IData)(__Vtask_tb_top__DOT__check_mesi__88__index),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__91__s 
                            = vlSelf->tb_top__DOT__check_mesi__Vstatic__actual;
                        __Vfunc_tb_top__DOT__mesi_name__91__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__91__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__91__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__91__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__91__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__91__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__91__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__91__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__91__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__91__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__91__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__91__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__91__Vfuncout).data(),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__92__s 
                            = __Vtask_tb_top__DOT__check_mesi__88__expected;
                        __Vfunc_tb_top__DOT__mesi_name__92__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__92__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__92__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__92__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__92__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__92__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__92__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__92__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__92__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__92__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__92__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__92__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__92__Vfuncout).data());
        vlSelf->tb_top__DOT__errors = ((IData)(1U) 
                                       + vlSelf->tb_top__DOT__errors);
    }
    __Vtask_tb_top__DOT__cpu_write__93__wdata = 0xb0000002U;
    __Vtask_tb_top__DOT__cpu_write__93__addr = 0x44U;
    __Vtask_tb_top__DOT__cpu_write__93__core = 1U;
    vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout = 0U;
    if ((0U == __Vtask_tb_top__DOT__cpu_write__93__core)) {
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           188);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c0_req = 1U;
        vlSelf->tb_top__DOT__c0_we = 1U;
        vlSelf->tb_top__DOT__c0_addr = __Vtask_tb_top__DOT__cpu_write__93__addr;
        vlSelf->tb_top__DOT__c0_wdata = __Vtask_tb_top__DOT__cpu_write__93__wdata;
        co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           190);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        while (((~ (IData)(vlSelf->tb_top__DOT__c0_ack)) 
                & VL_GTS_III(32, 0x32U, vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout))) {
            co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_top.clk)", 
                                                               "tb/tb_mesi_system.v", 
                                                               192);
            vlSelf->__Vm_traceActivity[2U] = 1U;
            vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout 
                = ((IData)(1U) + vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout);
        }
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           195);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c0_req = 0U;
        vlSelf->tb_top__DOT__c0_we = 0U;
    } else {
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           198);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c1_req = 1U;
        vlSelf->tb_top__DOT__c1_we = 1U;
        vlSelf->tb_top__DOT__c1_addr = __Vtask_tb_top__DOT__cpu_write__93__addr;
        vlSelf->tb_top__DOT__c1_wdata = __Vtask_tb_top__DOT__cpu_write__93__wdata;
        co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           200);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        while (((~ (IData)(vlSelf->tb_top__DOT__c1_ack)) 
                & VL_GTS_III(32, 0x32U, vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout))) {
            co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_top.clk)", 
                                                               "tb/tb_mesi_system.v", 
                                                               202);
            vlSelf->__Vm_traceActivity[2U] = 1U;
            vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout 
                = ((IData)(1U) + vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout);
        }
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           205);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c1_req = 0U;
        vlSelf->tb_top__DOT__c1_we = 0U;
    }
    if (VL_UNLIKELY(VL_LTES_III(32, 0x32U, vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout))) {
        VL_WRITEF("  [WARN] cpu_write core%0d timed out!\n",
                  32,__Vtask_tb_top__DOT__cpu_write__93__core);
    }
    __Vtask_tb_top__DOT__check_mesi__94__expected = 3U;
    __Vfunc_tb_top__DOT__addr_to_index__95__a = 0x44U;
    __Vfunc_tb_top__DOT__addr_to_index__95__Vfuncout 
        = (7U & ((IData)(__Vfunc_tb_top__DOT__addr_to_index__95__a) 
                 >> 2U));
    __Vtask_tb_top__DOT__check_mesi__94__index = __Vfunc_tb_top__DOT__addr_to_index__95__Vfuncout;
    __Vtask_tb_top__DOT__check_mesi__94__cache = 1U;
    vlSelf->tb_top__DOT__check_mesi__Vstatic__actual 
        = ((0U == __Vtask_tb_top__DOT__check_mesi__94__cache)
            ? vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi
           [__Vtask_tb_top__DOT__check_mesi__94__index]
            : vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi
           [__Vtask_tb_top__DOT__check_mesi__94__index]);
    if (((IData)(vlSelf->tb_top__DOT__check_mesi__Vstatic__actual) 
         == (IData)(__Vtask_tb_top__DOT__check_mesi__94__expected))) {
        VL_WRITEF("  [PASS] Cache%0d index%0# state = %s\n",
                  32,__Vtask_tb_top__DOT__check_mesi__94__cache,
                  3,(IData)(__Vtask_tb_top__DOT__check_mesi__94__index),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__96__s 
                            = vlSelf->tb_top__DOT__check_mesi__Vstatic__actual;
                        __Vfunc_tb_top__DOT__mesi_name__96__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__96__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__96__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__96__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__96__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__96__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__96__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__96__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__96__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__96__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__96__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__96__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__96__Vfuncout).data());
    } else {
        VL_WRITEF("  [FAIL] Cache%0d index%0# state = %s  (expected %s)\n",
                  32,__Vtask_tb_top__DOT__check_mesi__94__cache,
                  3,(IData)(__Vtask_tb_top__DOT__check_mesi__94__index),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__97__s 
                            = vlSelf->tb_top__DOT__check_mesi__Vstatic__actual;
                        __Vfunc_tb_top__DOT__mesi_name__97__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__97__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__97__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__97__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__97__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__97__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__97__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__97__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__97__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__97__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__97__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__97__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__97__Vfuncout).data(),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__98__s 
                            = __Vtask_tb_top__DOT__check_mesi__94__expected;
                        __Vfunc_tb_top__DOT__mesi_name__98__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__98__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__98__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__98__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__98__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__98__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__98__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__98__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__98__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__98__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__98__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__98__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__98__Vfuncout).data());
        vlSelf->tb_top__DOT__errors = ((IData)(1U) 
                                       + vlSelf->tb_top__DOT__errors);
    }
    __Vtask_tb_top__DOT__check_mesi__99__expected = 0U;
    __Vfunc_tb_top__DOT__addr_to_index__100__a = 0x44U;
    __Vfunc_tb_top__DOT__addr_to_index__100__Vfuncout 
        = (7U & ((IData)(__Vfunc_tb_top__DOT__addr_to_index__100__a) 
                 >> 2U));
    __Vtask_tb_top__DOT__check_mesi__99__index = __Vfunc_tb_top__DOT__addr_to_index__100__Vfuncout;
    __Vtask_tb_top__DOT__check_mesi__99__cache = 0U;
    vlSelf->tb_top__DOT__check_mesi__Vstatic__actual 
        = ((0U == __Vtask_tb_top__DOT__check_mesi__99__cache)
            ? vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi
           [__Vtask_tb_top__DOT__check_mesi__99__index]
            : vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi
           [__Vtask_tb_top__DOT__check_mesi__99__index]);
    if (((IData)(vlSelf->tb_top__DOT__check_mesi__Vstatic__actual) 
         == (IData)(__Vtask_tb_top__DOT__check_mesi__99__expected))) {
        VL_WRITEF("  [PASS] Cache%0d index%0# state = %s\n",
                  32,__Vtask_tb_top__DOT__check_mesi__99__cache,
                  3,(IData)(__Vtask_tb_top__DOT__check_mesi__99__index),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__101__s 
                            = vlSelf->tb_top__DOT__check_mesi__Vstatic__actual;
                        __Vfunc_tb_top__DOT__mesi_name__101__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__101__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__101__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__101__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__101__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__101__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__101__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__101__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__101__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__101__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__101__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__101__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__101__Vfuncout).data());
    } else {
        VL_WRITEF("  [FAIL] Cache%0d index%0# state = %s  (expected %s)\n",
                  32,__Vtask_tb_top__DOT__check_mesi__99__cache,
                  3,(IData)(__Vtask_tb_top__DOT__check_mesi__99__index),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__102__s 
                            = vlSelf->tb_top__DOT__check_mesi__Vstatic__actual;
                        __Vfunc_tb_top__DOT__mesi_name__102__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__102__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__102__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__102__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__102__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__102__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__102__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__102__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__102__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__102__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__102__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__102__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__102__Vfuncout).data(),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__103__s 
                            = __Vtask_tb_top__DOT__check_mesi__99__expected;
                        __Vfunc_tb_top__DOT__mesi_name__103__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__103__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__103__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__103__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__103__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__103__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__103__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__103__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__103__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__103__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__103__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__103__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__103__Vfuncout).data());
        vlSelf->tb_top__DOT__errors = ((IData)(1U) 
                                       + vlSelf->tb_top__DOT__errors);
    }
    VL_WRITEF("  Iteration 2: coherence maintained\n");
    co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_top.clk)", 
                                                       "tb/tb_mesi_system.v", 
                                                       426);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_top.clk)", 
                                                       "tb/tb_mesi_system.v", 
                                                       426);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb_top__DOT__stress__DOT__iter = 3U;
    __Vtask_tb_top__DOT__cpu_write__82__wdata = 0xa0000003U;
    __Vtask_tb_top__DOT__cpu_write__82__addr = 0x40U;
    __Vtask_tb_top__DOT__cpu_write__82__core = 0U;
    vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout = 0U;
    if ((0U == __Vtask_tb_top__DOT__cpu_write__82__core)) {
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           188);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c0_req = 1U;
        vlSelf->tb_top__DOT__c0_we = 1U;
        vlSelf->tb_top__DOT__c0_addr = __Vtask_tb_top__DOT__cpu_write__82__addr;
        vlSelf->tb_top__DOT__c0_wdata = __Vtask_tb_top__DOT__cpu_write__82__wdata;
        co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           190);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        while (((~ (IData)(vlSelf->tb_top__DOT__c0_ack)) 
                & VL_GTS_III(32, 0x32U, vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout))) {
            co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_top.clk)", 
                                                               "tb/tb_mesi_system.v", 
                                                               192);
            vlSelf->__Vm_traceActivity[2U] = 1U;
            vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout 
                = ((IData)(1U) + vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout);
        }
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           195);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c0_req = 0U;
        vlSelf->tb_top__DOT__c0_we = 0U;
    } else {
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           198);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c1_req = 1U;
        vlSelf->tb_top__DOT__c1_we = 1U;
        vlSelf->tb_top__DOT__c1_addr = __Vtask_tb_top__DOT__cpu_write__82__addr;
        vlSelf->tb_top__DOT__c1_wdata = __Vtask_tb_top__DOT__cpu_write__82__wdata;
        co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           200);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        while (((~ (IData)(vlSelf->tb_top__DOT__c1_ack)) 
                & VL_GTS_III(32, 0x32U, vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout))) {
            co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_top.clk)", 
                                                               "tb/tb_mesi_system.v", 
                                                               202);
            vlSelf->__Vm_traceActivity[2U] = 1U;
            vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout 
                = ((IData)(1U) + vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout);
        }
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           205);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c1_req = 0U;
        vlSelf->tb_top__DOT__c1_we = 0U;
    }
    if (VL_UNLIKELY(VL_LTES_III(32, 0x32U, vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout))) {
        VL_WRITEF("  [WARN] cpu_write core%0d timed out!\n",
                  32,__Vtask_tb_top__DOT__cpu_write__82__core);
    }
    __Vtask_tb_top__DOT__check_mesi__83__expected = 3U;
    __Vfunc_tb_top__DOT__addr_to_index__84__a = 0x40U;
    __Vfunc_tb_top__DOT__addr_to_index__84__Vfuncout 
        = (7U & ((IData)(__Vfunc_tb_top__DOT__addr_to_index__84__a) 
                 >> 2U));
    __Vtask_tb_top__DOT__check_mesi__83__index = __Vfunc_tb_top__DOT__addr_to_index__84__Vfuncout;
    __Vtask_tb_top__DOT__check_mesi__83__cache = 0U;
    vlSelf->tb_top__DOT__check_mesi__Vstatic__actual 
        = ((0U == __Vtask_tb_top__DOT__check_mesi__83__cache)
            ? vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi
           [__Vtask_tb_top__DOT__check_mesi__83__index]
            : vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi
           [__Vtask_tb_top__DOT__check_mesi__83__index]);
    if (((IData)(vlSelf->tb_top__DOT__check_mesi__Vstatic__actual) 
         == (IData)(__Vtask_tb_top__DOT__check_mesi__83__expected))) {
        VL_WRITEF("  [PASS] Cache%0d index%0# state = %s\n",
                  32,__Vtask_tb_top__DOT__check_mesi__83__cache,
                  3,(IData)(__Vtask_tb_top__DOT__check_mesi__83__index),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__85__s 
                            = vlSelf->tb_top__DOT__check_mesi__Vstatic__actual;
                        __Vfunc_tb_top__DOT__mesi_name__85__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__85__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__85__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__85__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__85__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__85__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__85__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__85__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__85__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__85__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__85__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__85__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__85__Vfuncout).data());
    } else {
        VL_WRITEF("  [FAIL] Cache%0d index%0# state = %s  (expected %s)\n",
                  32,__Vtask_tb_top__DOT__check_mesi__83__cache,
                  3,(IData)(__Vtask_tb_top__DOT__check_mesi__83__index),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__86__s 
                            = vlSelf->tb_top__DOT__check_mesi__Vstatic__actual;
                        __Vfunc_tb_top__DOT__mesi_name__86__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__86__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__86__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__86__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__86__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__86__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__86__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__86__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__86__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__86__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__86__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__86__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__86__Vfuncout).data(),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__87__s 
                            = __Vtask_tb_top__DOT__check_mesi__83__expected;
                        __Vfunc_tb_top__DOT__mesi_name__87__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__87__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__87__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__87__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__87__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__87__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__87__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__87__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__87__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__87__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__87__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__87__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__87__Vfuncout).data());
        vlSelf->tb_top__DOT__errors = ((IData)(1U) 
                                       + vlSelf->tb_top__DOT__errors);
    }
    __Vtask_tb_top__DOT__check_mesi__88__expected = 0U;
    __Vfunc_tb_top__DOT__addr_to_index__89__a = 0x40U;
    __Vfunc_tb_top__DOT__addr_to_index__89__Vfuncout 
        = (7U & ((IData)(__Vfunc_tb_top__DOT__addr_to_index__89__a) 
                 >> 2U));
    __Vtask_tb_top__DOT__check_mesi__88__index = __Vfunc_tb_top__DOT__addr_to_index__89__Vfuncout;
    __Vtask_tb_top__DOT__check_mesi__88__cache = 1U;
    vlSelf->tb_top__DOT__check_mesi__Vstatic__actual 
        = ((0U == __Vtask_tb_top__DOT__check_mesi__88__cache)
            ? vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi
           [__Vtask_tb_top__DOT__check_mesi__88__index]
            : vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi
           [__Vtask_tb_top__DOT__check_mesi__88__index]);
    if (((IData)(vlSelf->tb_top__DOT__check_mesi__Vstatic__actual) 
         == (IData)(__Vtask_tb_top__DOT__check_mesi__88__expected))) {
        VL_WRITEF("  [PASS] Cache%0d index%0# state = %s\n",
                  32,__Vtask_tb_top__DOT__check_mesi__88__cache,
                  3,(IData)(__Vtask_tb_top__DOT__check_mesi__88__index),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__90__s 
                            = vlSelf->tb_top__DOT__check_mesi__Vstatic__actual;
                        __Vfunc_tb_top__DOT__mesi_name__90__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__90__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__90__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__90__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__90__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__90__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__90__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__90__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__90__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__90__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__90__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__90__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__90__Vfuncout).data());
    } else {
        VL_WRITEF("  [FAIL] Cache%0d index%0# state = %s  (expected %s)\n",
                  32,__Vtask_tb_top__DOT__check_mesi__88__cache,
                  3,(IData)(__Vtask_tb_top__DOT__check_mesi__88__index),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__91__s 
                            = vlSelf->tb_top__DOT__check_mesi__Vstatic__actual;
                        __Vfunc_tb_top__DOT__mesi_name__91__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__91__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__91__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__91__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__91__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__91__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__91__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__91__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__91__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__91__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__91__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__91__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__91__Vfuncout).data(),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__92__s 
                            = __Vtask_tb_top__DOT__check_mesi__88__expected;
                        __Vfunc_tb_top__DOT__mesi_name__92__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__92__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__92__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__92__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__92__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__92__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__92__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__92__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__92__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__92__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__92__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__92__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__92__Vfuncout).data());
        vlSelf->tb_top__DOT__errors = ((IData)(1U) 
                                       + vlSelf->tb_top__DOT__errors);
    }
    __Vtask_tb_top__DOT__cpu_write__93__wdata = 0xb0000003U;
    __Vtask_tb_top__DOT__cpu_write__93__addr = 0x44U;
    __Vtask_tb_top__DOT__cpu_write__93__core = 1U;
    vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout = 0U;
    if ((0U == __Vtask_tb_top__DOT__cpu_write__93__core)) {
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           188);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c0_req = 1U;
        vlSelf->tb_top__DOT__c0_we = 1U;
        vlSelf->tb_top__DOT__c0_addr = __Vtask_tb_top__DOT__cpu_write__93__addr;
        vlSelf->tb_top__DOT__c0_wdata = __Vtask_tb_top__DOT__cpu_write__93__wdata;
        co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           190);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        while (((~ (IData)(vlSelf->tb_top__DOT__c0_ack)) 
                & VL_GTS_III(32, 0x32U, vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout))) {
            co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_top.clk)", 
                                                               "tb/tb_mesi_system.v", 
                                                               192);
            vlSelf->__Vm_traceActivity[2U] = 1U;
            vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout 
                = ((IData)(1U) + vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout);
        }
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           195);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c0_req = 0U;
        vlSelf->tb_top__DOT__c0_we = 0U;
    } else {
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           198);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c1_req = 1U;
        vlSelf->tb_top__DOT__c1_we = 1U;
        vlSelf->tb_top__DOT__c1_addr = __Vtask_tb_top__DOT__cpu_write__93__addr;
        vlSelf->tb_top__DOT__c1_wdata = __Vtask_tb_top__DOT__cpu_write__93__wdata;
        co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           200);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        while (((~ (IData)(vlSelf->tb_top__DOT__c1_ack)) 
                & VL_GTS_III(32, 0x32U, vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout))) {
            co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_top.clk)", 
                                                               "tb/tb_mesi_system.v", 
                                                               202);
            vlSelf->__Vm_traceActivity[2U] = 1U;
            vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout 
                = ((IData)(1U) + vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout);
        }
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           205);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c1_req = 0U;
        vlSelf->tb_top__DOT__c1_we = 0U;
    }
    if (VL_UNLIKELY(VL_LTES_III(32, 0x32U, vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout))) {
        VL_WRITEF("  [WARN] cpu_write core%0d timed out!\n",
                  32,__Vtask_tb_top__DOT__cpu_write__93__core);
    }
    __Vtask_tb_top__DOT__check_mesi__94__expected = 3U;
    __Vfunc_tb_top__DOT__addr_to_index__95__a = 0x44U;
    __Vfunc_tb_top__DOT__addr_to_index__95__Vfuncout 
        = (7U & ((IData)(__Vfunc_tb_top__DOT__addr_to_index__95__a) 
                 >> 2U));
    __Vtask_tb_top__DOT__check_mesi__94__index = __Vfunc_tb_top__DOT__addr_to_index__95__Vfuncout;
    __Vtask_tb_top__DOT__check_mesi__94__cache = 1U;
    vlSelf->tb_top__DOT__check_mesi__Vstatic__actual 
        = ((0U == __Vtask_tb_top__DOT__check_mesi__94__cache)
            ? vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi
           [__Vtask_tb_top__DOT__check_mesi__94__index]
            : vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi
           [__Vtask_tb_top__DOT__check_mesi__94__index]);
    if (((IData)(vlSelf->tb_top__DOT__check_mesi__Vstatic__actual) 
         == (IData)(__Vtask_tb_top__DOT__check_mesi__94__expected))) {
        VL_WRITEF("  [PASS] Cache%0d index%0# state = %s\n",
                  32,__Vtask_tb_top__DOT__check_mesi__94__cache,
                  3,(IData)(__Vtask_tb_top__DOT__check_mesi__94__index),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__96__s 
                            = vlSelf->tb_top__DOT__check_mesi__Vstatic__actual;
                        __Vfunc_tb_top__DOT__mesi_name__96__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__96__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__96__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__96__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__96__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__96__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__96__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__96__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__96__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__96__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__96__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__96__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__96__Vfuncout).data());
    } else {
        VL_WRITEF("  [FAIL] Cache%0d index%0# state = %s  (expected %s)\n",
                  32,__Vtask_tb_top__DOT__check_mesi__94__cache,
                  3,(IData)(__Vtask_tb_top__DOT__check_mesi__94__index),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__97__s 
                            = vlSelf->tb_top__DOT__check_mesi__Vstatic__actual;
                        __Vfunc_tb_top__DOT__mesi_name__97__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__97__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__97__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__97__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__97__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__97__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__97__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__97__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__97__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__97__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__97__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__97__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__97__Vfuncout).data(),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__98__s 
                            = __Vtask_tb_top__DOT__check_mesi__94__expected;
                        __Vfunc_tb_top__DOT__mesi_name__98__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__98__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__98__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__98__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__98__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__98__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__98__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__98__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__98__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__98__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__98__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__98__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__98__Vfuncout).data());
        vlSelf->tb_top__DOT__errors = ((IData)(1U) 
                                       + vlSelf->tb_top__DOT__errors);
    }
    __Vtask_tb_top__DOT__check_mesi__99__expected = 0U;
    __Vfunc_tb_top__DOT__addr_to_index__100__a = 0x44U;
    __Vfunc_tb_top__DOT__addr_to_index__100__Vfuncout 
        = (7U & ((IData)(__Vfunc_tb_top__DOT__addr_to_index__100__a) 
                 >> 2U));
    __Vtask_tb_top__DOT__check_mesi__99__index = __Vfunc_tb_top__DOT__addr_to_index__100__Vfuncout;
    __Vtask_tb_top__DOT__check_mesi__99__cache = 0U;
    vlSelf->tb_top__DOT__check_mesi__Vstatic__actual 
        = ((0U == __Vtask_tb_top__DOT__check_mesi__99__cache)
            ? vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi
           [__Vtask_tb_top__DOT__check_mesi__99__index]
            : vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi
           [__Vtask_tb_top__DOT__check_mesi__99__index]);
    if (((IData)(vlSelf->tb_top__DOT__check_mesi__Vstatic__actual) 
         == (IData)(__Vtask_tb_top__DOT__check_mesi__99__expected))) {
        VL_WRITEF("  [PASS] Cache%0d index%0# state = %s\n",
                  32,__Vtask_tb_top__DOT__check_mesi__99__cache,
                  3,(IData)(__Vtask_tb_top__DOT__check_mesi__99__index),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__101__s 
                            = vlSelf->tb_top__DOT__check_mesi__Vstatic__actual;
                        __Vfunc_tb_top__DOT__mesi_name__101__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__101__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__101__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__101__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__101__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__101__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__101__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__101__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__101__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__101__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__101__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__101__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__101__Vfuncout).data());
    } else {
        VL_WRITEF("  [FAIL] Cache%0d index%0# state = %s  (expected %s)\n",
                  32,__Vtask_tb_top__DOT__check_mesi__99__cache,
                  3,(IData)(__Vtask_tb_top__DOT__check_mesi__99__index),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__102__s 
                            = vlSelf->tb_top__DOT__check_mesi__Vstatic__actual;
                        __Vfunc_tb_top__DOT__mesi_name__102__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__102__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__102__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__102__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__102__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__102__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__102__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__102__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__102__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__102__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__102__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__102__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__102__Vfuncout).data(),
                  80,([&]() {
                        __Vfunc_tb_top__DOT__mesi_name__103__s 
                            = __Vtask_tb_top__DOT__check_mesi__99__expected;
                        __Vfunc_tb_top__DOT__mesi_name__103__Vfuncout[0U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__103__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__103__s))
                                    ? 0x69656429U : 0x69766529U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__103__s))
                                    ? 0x29202020U : 0x64292020U));
                        __Vfunc_tb_top__DOT__mesi_name__103__Vfuncout[1U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__103__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__103__s))
                                    ? 0x6f646966U : 0x636c7573U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__103__s))
                                    ? 0x61726564U : 0x76616c69U));
                        __Vfunc_tb_top__DOT__mesi_name__103__Vfuncout[2U] 
                            = ((2U & (IData)(__Vfunc_tb_top__DOT__mesi_name__103__s))
                                ? ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__103__s))
                                    ? 0x284dU : 0x4578U)
                                : ((1U & (IData)(__Vfunc_tb_top__DOT__mesi_name__103__s))
                                    ? 0x5368U : 0x496eU));
                    }(), __Vfunc_tb_top__DOT__mesi_name__103__Vfuncout).data());
        vlSelf->tb_top__DOT__errors = ((IData)(1U) 
                                       + vlSelf->tb_top__DOT__errors);
    }
    VL_WRITEF("  Iteration 3: coherence maintained\n");
    co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_top.clk)", 
                                                       "tb/tb_mesi_system.v", 
                                                       426);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_top.clk)", 
                                                       "tb/tb_mesi_system.v", 
                                                       426);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb_top__DOT__stress__DOT__iter = 4U;
    __Vtask_tb_top__DOT__separator__104__name[0U] = 
        Vtb_top__ConstPool__CONST_h11665c5b_0[0U];
    __Vtask_tb_top__DOT__separator__104__name[1U] = 
        Vtb_top__ConstPool__CONST_h11665c5b_0[1U];
    __Vtask_tb_top__DOT__separator__104__name[2U] = 
        Vtb_top__ConstPool__CONST_h11665c5b_0[2U];
    __Vtask_tb_top__DOT__separator__104__name[3U] = 
        Vtb_top__ConstPool__CONST_h11665c5b_0[3U];
    __Vtask_tb_top__DOT__separator__104__name[4U] = 
        Vtb_top__ConstPool__CONST_h11665c5b_0[4U];
    __Vtask_tb_top__DOT__separator__104__name[5U] = 
        Vtb_top__ConstPool__CONST_h11665c5b_0[5U];
    __Vtask_tb_top__DOT__separator__104__name[6U] = 
        Vtb_top__ConstPool__CONST_h11665c5b_0[6U];
    __Vtask_tb_top__DOT__separator__104__name[7U] = 
        Vtb_top__ConstPool__CONST_h11665c5b_0[7U];
    VL_WRITEF("\n============================================================\n %s\n============================================================\n",
              256,__Vtask_tb_top__DOT__separator__104__name.data());
    __Vtask_tb_top__DOT__cpu_read__105__addr = 0x44U;
    __Vtask_tb_top__DOT__cpu_read__105__core = 0U;
    vlSelf->tb_top__DOT__cpu_read__Vstatic__timeout = 0U;
    if ((0U == __Vtask_tb_top__DOT__cpu_read__105__core)) {
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           151);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c0_req = 1U;
        vlSelf->tb_top__DOT__c0_we = 0U;
        vlSelf->tb_top__DOT__c0_addr = __Vtask_tb_top__DOT__cpu_read__105__addr;
        co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           153);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        while (((~ (IData)(vlSelf->tb_top__DOT__c0_ack)) 
                & VL_GTS_III(32, 0x32U, vlSelf->tb_top__DOT__cpu_read__Vstatic__timeout))) {
            co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_top.clk)", 
                                                               "tb/tb_mesi_system.v", 
                                                               155);
            vlSelf->__Vm_traceActivity[2U] = 1U;
            vlSelf->tb_top__DOT__cpu_read__Vstatic__timeout 
                = ((IData)(1U) + vlSelf->tb_top__DOT__cpu_read__Vstatic__timeout);
        }
        __Vtask_tb_top__DOT__cpu_read__105__rdata = vlSelf->tb_top__DOT__c0_rdata;
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           159);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c0_req = 0U;
    } else {
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           162);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c1_req = 1U;
        vlSelf->tb_top__DOT__c1_we = 0U;
        vlSelf->tb_top__DOT__c1_addr = __Vtask_tb_top__DOT__cpu_read__105__addr;
        co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           164);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        while (((~ (IData)(vlSelf->tb_top__DOT__c1_ack)) 
                & VL_GTS_III(32, 0x32U, vlSelf->tb_top__DOT__cpu_read__Vstatic__timeout))) {
            co_await vlSelf->__VtrigSched_he3ce3317__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_top.clk)", 
                                                               "tb/tb_mesi_system.v", 
                                                               166);
            vlSelf->__Vm_traceActivity[2U] = 1U;
            vlSelf->tb_top__DOT__cpu_read__Vstatic__timeout 
                = ((IData)(1U) + vlSelf->tb_top__DOT__cpu_read__Vstatic__timeout);
        }
        __Vtask_tb_top__DOT__cpu_read__105__rdata = vlSelf->tb_top__DOT__c1_rdata;
        co_await vlSelf->__VtrigSched_he3ce33ca__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_top.clk)", 
                                                           "tb/tb_mesi_system.v", 
                                                           170);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_top__DOT__c1_req = 0U;
    }
    if (VL_UNLIKELY(VL_LTES_III(32, 0x32U, vlSelf->tb_top__DOT__cpu_read__Vstatic__timeout))) {
        VL_WRITEF("  [WARN] cpu_read core%0d timed out!\n",
                  32,__Vtask_tb_top__DOT__cpu_read__105__core);
    }
    vlSelf->tb_top__DOT__rdata0 = __Vtask_tb_top__DOT__cpu_read__105__rdata;
    __Vtask_tb_top__DOT__check_data__106__label[0U] = 0x30783434U;
    __Vtask_tb_top__DOT__check_data__106__label[1U] = 0x20746f20U;
    __Vtask_tb_top__DOT__check_data__106__label[2U] = 0x72697465U;
    __Vtask_tb_top__DOT__check_data__106__label[3U] = 0x73742077U;
    __Vtask_tb_top__DOT__check_data__106__expected = 0xb0000003U;
    __Vtask_tb_top__DOT__check_data__106__actual = vlSelf->tb_top__DOT__rdata0;
    if ((__Vtask_tb_top__DOT__check_data__106__actual 
         == __Vtask_tb_top__DOT__check_data__106__expected)) {
        VL_WRITEF("  [PASS] %s = 0x%08x\n",128,__Vtask_tb_top__DOT__check_data__106__label.data(),
                  32,__Vtask_tb_top__DOT__check_data__106__actual);
    } else {
        VL_WRITEF("  [FAIL] %s = 0x%08x  (expected 0x%08x)\n",
                  128,__Vtask_tb_top__DOT__check_data__106__label.data(),
                  32,__Vtask_tb_top__DOT__check_data__106__actual,
                  32,__Vtask_tb_top__DOT__check_data__106__expected);
        vlSelf->tb_top__DOT__errors = ((IData)(1U) 
                                       + vlSelf->tb_top__DOT__errors);
    }
    __Vtask_tb_top__DOT__separator__107__name[0U] = 
        Vtb_top__ConstPool__CONST_hff5f4d65_0[0U];
    __Vtask_tb_top__DOT__separator__107__name[1U] = 
        Vtb_top__ConstPool__CONST_hff5f4d65_0[1U];
    __Vtask_tb_top__DOT__separator__107__name[2U] = 
        Vtb_top__ConstPool__CONST_hff5f4d65_0[2U];
    __Vtask_tb_top__DOT__separator__107__name[3U] = 
        Vtb_top__ConstPool__CONST_hff5f4d65_0[3U];
    __Vtask_tb_top__DOT__separator__107__name[4U] = 
        Vtb_top__ConstPool__CONST_hff5f4d65_0[4U];
    __Vtask_tb_top__DOT__separator__107__name[5U] = 
        Vtb_top__ConstPool__CONST_hff5f4d65_0[5U];
    __Vtask_tb_top__DOT__separator__107__name[6U] = 
        Vtb_top__ConstPool__CONST_hff5f4d65_0[6U];
    __Vtask_tb_top__DOT__separator__107__name[7U] = 
        Vtb_top__ConstPool__CONST_hff5f4d65_0[7U];
    VL_WRITEF("\n============================================================\n %s\n============================================================\n  Total BusRd         : %0d\n  Total BusInvalidate : %0d\n  Total BusWriteback  : %0d\n  Total bus txns      : %0d\n",
              256,__Vtask_tb_top__DOT__separator__107__name.data(),
              32,vlSelf->tb_top__DOT__cnt_busrd,32,
              vlSelf->tb_top__DOT__cnt_busInv,32,vlSelf->tb_top__DOT__cnt_buswb,
              32,((vlSelf->tb_top__DOT__cnt_busrd + vlSelf->tb_top__DOT__cnt_busInv) 
                  + vlSelf->tb_top__DOT__cnt_buswb));
    VL_WRITEF("\n  MESI Protocol coverage:\n    I -> E  (cold read, exclusive)      : Test 1,6\n    E -> S  (another cache reads same)  : Test 3\n    S -> M  (write, BusInv issued)      : Test 4\n    M -> S  (another cache reads dirty) : Test 5\n    M -> I  (eviction, BusWB issued)    : Test 7\n    E -> M  (write to exclusive, silent): Test 6\n    S -> I  (snooped BusInv)            : Test 4\n\n");
    __Vtask_tb_top__DOT__separator__108__name[0U] = 
        Vtb_top__ConstPool__CONST_h64d54945_0[0U];
    __Vtask_tb_top__DOT__separator__108__name[1U] = 
        Vtb_top__ConstPool__CONST_h64d54945_0[1U];
    __Vtask_tb_top__DOT__separator__108__name[2U] = 
        Vtb_top__ConstPool__CONST_h64d54945_0[2U];
    __Vtask_tb_top__DOT__separator__108__name[3U] = 
        Vtb_top__ConstPool__CONST_h64d54945_0[3U];
    __Vtask_tb_top__DOT__separator__108__name[4U] = 
        Vtb_top__ConstPool__CONST_h64d54945_0[4U];
    __Vtask_tb_top__DOT__separator__108__name[5U] = 
        Vtb_top__ConstPool__CONST_h64d54945_0[5U];
    __Vtask_tb_top__DOT__separator__108__name[6U] = 
        Vtb_top__ConstPool__CONST_h64d54945_0[6U];
    __Vtask_tb_top__DOT__separator__108__name[7U] = 
        Vtb_top__ConstPool__CONST_h64d54945_0[7U];
    VL_WRITEF("\n============================================================\n %s\n============================================================\n",
              256,__Vtask_tb_top__DOT__separator__108__name.data());
    if (VL_LTS_III(32, 0U, vlSelf->tb_top__DOT__errors)) {
        VL_WRITEF("  Test         : FAIL\n  Found errors : %11d\n",
                  32,vlSelf->tb_top__DOT__errors);
    } else {
        VL_WRITEF("  Test         : PASS\n");
    }
    VL_FINISH_MT("tb/tb_mesi_system.v", 463, "");
    vlSelf->__Vm_traceActivity[2U] = 1U;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_top___024root___dump_triggers__act(Vtb_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_top___024root___eval_triggers__act(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, ((IData)(vlSelf->tb_top__DOT__clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_top__DOT__clk__0))));
    vlSelf->__VactTriggered.set(1U, ((~ (IData)(vlSelf->tb_top__DOT__clk)) 
                                     & (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_top__DOT__clk__0)));
    vlSelf->__VactTriggered.set(2U, vlSelf->__VdlySched.awaitingCurrentTime());
    vlSelf->__Vtrigprevexpr___TOP__tb_top__DOT__clk__0 
        = vlSelf->tb_top__DOT__clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_top___024root___dump_triggers__act(vlSelf);
    }
#endif
}
