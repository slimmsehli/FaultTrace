// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_top.h for the primary calling header

#include "Vtb_top__pch.h"
#include "Vtb_top___024root.h"

VL_ATTR_COLD void Vtb_top___024root___eval_initial__TOP(Vtb_top___024root* vlSelf);
VlCoroutine Vtb_top___024root___eval_initial__TOP__Vtiming__0(Vtb_top___024root* vlSelf);
VlCoroutine Vtb_top___024root___eval_initial__TOP__Vtiming__1(Vtb_top___024root* vlSelf);
VlCoroutine Vtb_top___024root___eval_initial__TOP__Vtiming__2(Vtb_top___024root* vlSelf);

void Vtb_top___024root___eval_initial(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___eval_initial\n"); );
    // Body
    Vtb_top___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    Vtb_top___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_top___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    Vtb_top___024root___eval_initial__TOP__Vtiming__2(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__tb_top__DOT__clk__0 
        = vlSelf->tb_top__DOT__clk;
}

VL_INLINE_OPT VlCoroutine Vtb_top___024root___eval_initial__TOP__Vtiming__1(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___eval_initial__TOP__Vtiming__1\n"); );
    // Body
    co_await vlSelf->__VdlySched.delay(0x5f5e100ULL, 
                                       nullptr, "tb/tb_mesi_system.v", 
                                       470);
    VL_WRITEF("[WATCHDOG] Simulation exceeded time limit \342\200\224 possible deadlock!\n");
    VL_FINISH_MT("tb/tb_mesi_system.v", 472, "");
}

VL_INLINE_OPT VlCoroutine Vtb_top___024root___eval_initial__TOP__Vtiming__2(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___eval_initial__TOP__Vtiming__2\n"); );
    // Body
    while (1U) {
        co_await vlSelf->__VdlySched.delay(0x1388ULL, 
                                           nullptr, 
                                           "tb/tb_mesi_system.v", 
                                           59);
        vlSelf->tb_top__DOT__clk = (1U & (~ (IData)(vlSelf->tb_top__DOT__clk)));
    }
}

VL_INLINE_OPT void Vtb_top___024root___act_comb__TOP__0(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___act_comb__TOP__0\n"); );
    // Init
    CData/*1:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__109__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__109__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__109__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__109__a = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__110__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__110__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__110__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__110__a = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_tag__111__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_tag__111__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_tag__111__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_tag__111__a = 0;
    CData/*1:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__143__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__143__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__143__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__143__a = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__144__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__144__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__144__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__144__a = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_tag__145__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_tag__145__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_tag__145__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_tag__145__a = 0;
    // Body
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__109__a 
        = vlSelf->tb_top__DOT__c0_addr;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__109__Vfuncout 
        = (3U & (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__109__a));
    vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__cpu_offset 
        = __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__109__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__143__a 
        = vlSelf->tb_top__DOT__c1_addr;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__143__Vfuncout 
        = (3U & (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__143__a));
    vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__cpu_offset 
        = __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__143__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__110__a 
        = vlSelf->tb_top__DOT__c0_addr;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__110__Vfuncout 
        = (7U & ((IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__110__a) 
                 >> 2U));
    vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__cpu_index 
        = __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__110__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_tag__111__a 
        = vlSelf->tb_top__DOT__c0_addr;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_tag__111__Vfuncout 
        = (7U & ((IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_tag__111__a) 
                 >> 5U));
    vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__cpu_tag 
        = __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_tag__111__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__144__a 
        = vlSelf->tb_top__DOT__c1_addr;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__144__Vfuncout 
        = (7U & ((IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__144__a) 
                 >> 2U));
    vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__cpu_index 
        = __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__144__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_tag__145__a 
        = vlSelf->tb_top__DOT__c1_addr;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_tag__145__Vfuncout 
        = (7U & ((IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_tag__145__a) 
                 >> 5U));
    vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__cpu_tag 
        = __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_tag__145__Vfuncout;
    vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__hit 
        = ((IData)(vlSelf->tb_top__DOT__c0_req) & (
                                                   (0U 
                                                    != 
                                                    vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi
                                                    [vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__cpu_index]) 
                                                   & (vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__tag
                                                      [vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__cpu_index] 
                                                      == (IData)(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__cpu_tag))));
    vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__hit 
        = ((IData)(vlSelf->tb_top__DOT__c1_req) & (
                                                   (0U 
                                                    != 
                                                    vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi
                                                    [vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__cpu_index]) 
                                                   & (vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__tag
                                                      [vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__cpu_index] 
                                                      == (IData)(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__cpu_tag))));
}

void Vtb_top___024root___eval_act(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___eval_act\n"); );
    // Body
    if ((3ULL & vlSelf->__VactTriggered.word(0U))) {
        Vtb_top___024root___act_comb__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[3U] = 1U;
    }
}

VL_INLINE_OPT void Vtb_top___024root___nba_sequent__TOP__0(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__112__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__112__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__112__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__112__a = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_tag__113__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_tag__113__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_tag__113__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_tag__113__a = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__114__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__114__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__114__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__114__a = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__115__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__115__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__115__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__115__a = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__116__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__116__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__116__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__116__a = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__117__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__117__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__117__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__117__a = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__118__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__118__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__118__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__118__a = 0;
    CData/*1:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__119__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__119__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__119__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__119__a = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__120__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__120__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__120__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__120__a = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__121__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__121__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__121__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__121__a = 0;
    CData/*1:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__122__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__122__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__122__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__122__a = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__123__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__123__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__123__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__123__a = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__124__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__124__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__124__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__124__a = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__125__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__125__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__125__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__125__a = 0;
    CData/*1:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__126__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__126__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__126__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__126__a = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__127__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__127__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__127__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__127__a = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__128__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__128__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__128__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__128__a = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__129__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__129__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__129__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__129__a = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__130__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__130__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__130__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__130__a = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__131__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__131__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__131__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__131__a = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__132__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__132__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__132__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__132__a = 0;
    CData/*1:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__133__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__133__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__133__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__133__a = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__134__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__134__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__134__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__134__a = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_tag__135__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_tag__135__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_tag__135__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_tag__135__a = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__136__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__136__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__136__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__136__a = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__137__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__137__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__137__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__137__a = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__138__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__138__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__138__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__138__a = 0;
    CData/*1:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__139__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__139__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__139__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__139__a = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__140__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__140__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__140__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__140__a = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__141__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__141__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__141__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__141__a = 0;
    CData/*1:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__142__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__142__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__142__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__142__a = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__146__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__146__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__146__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__146__a = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_tag__147__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_tag__147__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_tag__147__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_tag__147__a = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__148__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__148__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__148__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__148__a = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__149__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__149__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__149__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__149__a = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__150__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__150__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__150__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__150__a = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__151__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__151__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__151__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__151__a = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__152__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__152__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__152__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__152__a = 0;
    CData/*1:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__153__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__153__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__153__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__153__a = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__154__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__154__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__154__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__154__a = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__155__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__155__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__155__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__155__a = 0;
    CData/*1:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__156__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__156__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__156__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__156__a = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__157__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__157__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__157__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__157__a = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__158__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__158__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__158__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__158__a = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__159__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__159__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__159__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__159__a = 0;
    CData/*1:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__160__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__160__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__160__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__160__a = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__161__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__161__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__161__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__161__a = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__162__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__162__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__162__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__162__a = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__163__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__163__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__163__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__163__a = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__164__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__164__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__164__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__164__a = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__165__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__165__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__165__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__165__a = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__166__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__166__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__166__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__166__a = 0;
    CData/*1:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__167__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__167__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__167__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__167__a = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__168__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__168__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__168__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__168__a = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_tag__169__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_tag__169__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_tag__169__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_tag__169__a = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__170__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__170__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__170__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__170__a = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__171__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__171__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__171__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__171__a = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__172__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__172__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__172__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__172__a = 0;
    CData/*1:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__173__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__173__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__173__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__173__a = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__174__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__174__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__174__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__174__a = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__175__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__175__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__175__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__175__a = 0;
    CData/*1:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__176__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__176__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__176__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__176__a = 0;
    CData/*1:0*/ __Vdly__tb_top__DOT__dut__DOT__bus_grant;
    __Vdly__tb_top__DOT__dut__DOT__bus_grant = 0;
    CData/*0:0*/ __Vdly__tb_top__DOT__dut__DOT__u_arb__DOT__last;
    __Vdly__tb_top__DOT__dut__DOT__u_arb__DOT__last = 0;
    CData/*2:0*/ __Vdly__tb_top__DOT__dut__DOT__u_cache0__DOT__state;
    __Vdly__tb_top__DOT__dut__DOT__u_cache0__DOT__state = 0;
    CData/*0:0*/ __Vdly__tb_top__DOT__dut__DOT__snoop_shared_c0;
    __Vdly__tb_top__DOT__dut__DOT__snoop_shared_c0 = 0;
    CData/*0:0*/ __Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v0;
    __Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v0 = 0;
    CData/*2:0*/ __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v8;
    __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v8 = 0;
    CData/*0:0*/ __Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v8;
    __Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v8 = 0;
    CData/*2:0*/ __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v9;
    __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v9 = 0;
    CData/*0:0*/ __Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v9;
    __Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v9 = 0;
    CData/*2:0*/ __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v10;
    __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v10 = 0;
    CData/*0:0*/ __Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v10;
    __Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v10 = 0;
    CData/*0:0*/ __Vdly__tb_top__DOT__dut__DOT__u_cache0__DOT__pending_we;
    __Vdly__tb_top__DOT__dut__DOT__u_cache0__DOT__pending_we = 0;
    CData/*7:0*/ __Vdly__tb_top__DOT__dut__DOT__u_cache0__DOT__pending_addr;
    __Vdly__tb_top__DOT__dut__DOT__u_cache0__DOT__pending_addr = 0;
    IData/*31:0*/ __Vdly__tb_top__DOT__dut__DOT__u_cache0__DOT__pending_wdata;
    __Vdly__tb_top__DOT__dut__DOT__u_cache0__DOT__pending_wdata = 0;
    CData/*2:0*/ __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v8;
    __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v8 = 0;
    CData/*6:0*/ __Vdlyvlsb__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v8;
    __Vdlyvlsb__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v8 = 0;
    IData/*31:0*/ __Vdlyvval__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v8;
    __Vdlyvval__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v8 = 0;
    CData/*0:0*/ __Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v8;
    __Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v8 = 0;
    CData/*2:0*/ __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v9;
    __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v9 = 0;
    CData/*6:0*/ __Vdlyvlsb__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v9;
    __Vdlyvlsb__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v9 = 0;
    IData/*31:0*/ __Vdlyvval__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v9;
    __Vdlyvval__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v9 = 0;
    CData/*0:0*/ __Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v9;
    __Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v9 = 0;
    CData/*2:0*/ __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v11;
    __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v11 = 0;
    CData/*0:0*/ __Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v11;
    __Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v11 = 0;
    CData/*1:0*/ __Vdly__tb_top__DOT__dut__DOT__bus_cmd_c0;
    __Vdly__tb_top__DOT__dut__DOT__bus_cmd_c0 = 0;
    CData/*2:0*/ __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v12;
    __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v12 = 0;
    CData/*0:0*/ __Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v12;
    __Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v12 = 0;
    CData/*2:0*/ __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v10;
    __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v10 = 0;
    CData/*6:0*/ __Vdlyvlsb__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v10;
    __Vdlyvlsb__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v10 = 0;
    IData/*31:0*/ __Vdlyvval__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v10;
    __Vdlyvval__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v10 = 0;
    CData/*0:0*/ __Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v10;
    __Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v10 = 0;
    CData/*2:0*/ __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v13;
    __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v13 = 0;
    CData/*0:0*/ __Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v13;
    __Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v13 = 0;
    CData/*2:0*/ __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache0__DOT__tag__v8;
    __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache0__DOT__tag__v8 = 0;
    CData/*2:0*/ __Vdlyvval__tb_top__DOT__dut__DOT__u_cache0__DOT__tag__v8;
    __Vdlyvval__tb_top__DOT__dut__DOT__u_cache0__DOT__tag__v8 = 0;
    CData/*0:0*/ __Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__tag__v8;
    __Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__tag__v8 = 0;
    CData/*2:0*/ __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v11;
    __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v11 = 0;
    VlWide<4>/*127:0*/ __Vdlyvval__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v11;
    VL_ZERO_W(128, __Vdlyvval__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v11);
    CData/*0:0*/ __Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v11;
    __Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v11 = 0;
    CData/*2:0*/ __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v12;
    __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v12 = 0;
    CData/*6:0*/ __Vdlyvlsb__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v12;
    __Vdlyvlsb__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v12 = 0;
    IData/*31:0*/ __Vdlyvval__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v12;
    __Vdlyvval__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v12 = 0;
    CData/*0:0*/ __Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v12;
    __Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v12 = 0;
    CData/*2:0*/ __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v14;
    __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v14 = 0;
    CData/*2:0*/ __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v15;
    __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v15 = 0;
    CData/*1:0*/ __Vdlyvval__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v15;
    __Vdlyvval__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v15 = 0;
    CData/*0:0*/ __Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v15;
    __Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v15 = 0;
    CData/*2:0*/ __Vdly__tb_top__DOT__dut__DOT__u_cache1__DOT__state;
    __Vdly__tb_top__DOT__dut__DOT__u_cache1__DOT__state = 0;
    CData/*0:0*/ __Vdly__tb_top__DOT__dut__DOT__snoop_shared_c1;
    __Vdly__tb_top__DOT__dut__DOT__snoop_shared_c1 = 0;
    CData/*0:0*/ __Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v0;
    __Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v0 = 0;
    CData/*2:0*/ __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v8;
    __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v8 = 0;
    CData/*0:0*/ __Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v8;
    __Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v8 = 0;
    CData/*2:0*/ __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v9;
    __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v9 = 0;
    CData/*0:0*/ __Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v9;
    __Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v9 = 0;
    CData/*2:0*/ __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v10;
    __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v10 = 0;
    CData/*0:0*/ __Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v10;
    __Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v10 = 0;
    CData/*0:0*/ __Vdly__tb_top__DOT__dut__DOT__u_cache1__DOT__pending_we;
    __Vdly__tb_top__DOT__dut__DOT__u_cache1__DOT__pending_we = 0;
    CData/*7:0*/ __Vdly__tb_top__DOT__dut__DOT__u_cache1__DOT__pending_addr;
    __Vdly__tb_top__DOT__dut__DOT__u_cache1__DOT__pending_addr = 0;
    IData/*31:0*/ __Vdly__tb_top__DOT__dut__DOT__u_cache1__DOT__pending_wdata;
    __Vdly__tb_top__DOT__dut__DOT__u_cache1__DOT__pending_wdata = 0;
    CData/*2:0*/ __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v8;
    __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v8 = 0;
    CData/*6:0*/ __Vdlyvlsb__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v8;
    __Vdlyvlsb__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v8 = 0;
    IData/*31:0*/ __Vdlyvval__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v8;
    __Vdlyvval__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v8 = 0;
    CData/*0:0*/ __Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v8;
    __Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v8 = 0;
    CData/*2:0*/ __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v9;
    __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v9 = 0;
    CData/*6:0*/ __Vdlyvlsb__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v9;
    __Vdlyvlsb__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v9 = 0;
    IData/*31:0*/ __Vdlyvval__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v9;
    __Vdlyvval__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v9 = 0;
    CData/*0:0*/ __Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v9;
    __Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v9 = 0;
    CData/*2:0*/ __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v11;
    __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v11 = 0;
    CData/*0:0*/ __Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v11;
    __Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v11 = 0;
    CData/*1:0*/ __Vdly__tb_top__DOT__dut__DOT__bus_cmd_c1;
    __Vdly__tb_top__DOT__dut__DOT__bus_cmd_c1 = 0;
    CData/*2:0*/ __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v12;
    __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v12 = 0;
    CData/*0:0*/ __Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v12;
    __Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v12 = 0;
    CData/*2:0*/ __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v10;
    __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v10 = 0;
    CData/*6:0*/ __Vdlyvlsb__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v10;
    __Vdlyvlsb__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v10 = 0;
    IData/*31:0*/ __Vdlyvval__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v10;
    __Vdlyvval__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v10 = 0;
    CData/*0:0*/ __Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v10;
    __Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v10 = 0;
    CData/*2:0*/ __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v13;
    __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v13 = 0;
    CData/*0:0*/ __Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v13;
    __Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v13 = 0;
    CData/*2:0*/ __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache1__DOT__tag__v8;
    __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache1__DOT__tag__v8 = 0;
    CData/*2:0*/ __Vdlyvval__tb_top__DOT__dut__DOT__u_cache1__DOT__tag__v8;
    __Vdlyvval__tb_top__DOT__dut__DOT__u_cache1__DOT__tag__v8 = 0;
    CData/*0:0*/ __Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__tag__v8;
    __Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__tag__v8 = 0;
    CData/*2:0*/ __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v11;
    __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v11 = 0;
    VlWide<4>/*127:0*/ __Vdlyvval__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v11;
    VL_ZERO_W(128, __Vdlyvval__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v11);
    CData/*0:0*/ __Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v11;
    __Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v11 = 0;
    CData/*2:0*/ __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v12;
    __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v12 = 0;
    CData/*6:0*/ __Vdlyvlsb__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v12;
    __Vdlyvlsb__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v12 = 0;
    IData/*31:0*/ __Vdlyvval__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v12;
    __Vdlyvval__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v12 = 0;
    CData/*0:0*/ __Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v12;
    __Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v12 = 0;
    CData/*2:0*/ __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v14;
    __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v14 = 0;
    CData/*2:0*/ __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v15;
    __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v15 = 0;
    CData/*1:0*/ __Vdlyvval__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v15;
    __Vdlyvval__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v15 = 0;
    CData/*0:0*/ __Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v15;
    __Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v15 = 0;
    CData/*7:0*/ __Vdlyvdim0__tb_top__DOT__dut__DOT__u_mem__DOT__mem__v0;
    __Vdlyvdim0__tb_top__DOT__dut__DOT__u_mem__DOT__mem__v0 = 0;
    IData/*31:0*/ __Vdlyvval__tb_top__DOT__dut__DOT__u_mem__DOT__mem__v0;
    __Vdlyvval__tb_top__DOT__dut__DOT__u_mem__DOT__mem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__tb_top__DOT__dut__DOT__u_mem__DOT__mem__v0;
    __Vdlyvset__tb_top__DOT__dut__DOT__u_mem__DOT__mem__v0 = 0;
    CData/*7:0*/ __Vdlyvdim0__tb_top__DOT__dut__DOT__u_mem__DOT__mem__v1;
    __Vdlyvdim0__tb_top__DOT__dut__DOT__u_mem__DOT__mem__v1 = 0;
    IData/*31:0*/ __Vdlyvval__tb_top__DOT__dut__DOT__u_mem__DOT__mem__v1;
    __Vdlyvval__tb_top__DOT__dut__DOT__u_mem__DOT__mem__v1 = 0;
    CData/*7:0*/ __Vdlyvdim0__tb_top__DOT__dut__DOT__u_mem__DOT__mem__v2;
    __Vdlyvdim0__tb_top__DOT__dut__DOT__u_mem__DOT__mem__v2 = 0;
    IData/*31:0*/ __Vdlyvval__tb_top__DOT__dut__DOT__u_mem__DOT__mem__v2;
    __Vdlyvval__tb_top__DOT__dut__DOT__u_mem__DOT__mem__v2 = 0;
    CData/*7:0*/ __Vdlyvdim0__tb_top__DOT__dut__DOT__u_mem__DOT__mem__v3;
    __Vdlyvdim0__tb_top__DOT__dut__DOT__u_mem__DOT__mem__v3 = 0;
    IData/*31:0*/ __Vdlyvval__tb_top__DOT__dut__DOT__u_mem__DOT__mem__v3;
    __Vdlyvval__tb_top__DOT__dut__DOT__u_mem__DOT__mem__v3 = 0;
    // Body
    __Vdly__tb_top__DOT__dut__DOT__u_arb__DOT__last 
        = vlSelf->tb_top__DOT__dut__DOT__u_arb__DOT__last;
    __Vdly__tb_top__DOT__dut__DOT__bus_grant = vlSelf->tb_top__DOT__dut__DOT__bus_grant;
    __Vdlyvset__tb_top__DOT__dut__DOT__u_mem__DOT__mem__v0 = 0U;
    __Vdly__tb_top__DOT__dut__DOT__u_cache1__DOT__pending_wdata 
        = vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__pending_wdata;
    __Vdly__tb_top__DOT__dut__DOT__u_cache1__DOT__pending_addr 
        = vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__pending_addr;
    __Vdly__tb_top__DOT__dut__DOT__u_cache1__DOT__pending_we 
        = vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__pending_we;
    __Vdly__tb_top__DOT__dut__DOT__snoop_shared_c1 
        = vlSelf->tb_top__DOT__dut__DOT__snoop_shared_c1;
    __Vdly__tb_top__DOT__dut__DOT__u_cache1__DOT__state 
        = vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__state;
    __Vdly__tb_top__DOT__dut__DOT__bus_cmd_c1 = vlSelf->tb_top__DOT__dut__DOT__bus_cmd_c1;
    __Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__tag__v8 = 0U;
    __Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v8 = 0U;
    __Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v9 = 0U;
    __Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v10 = 0U;
    __Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v11 = 0U;
    __Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v8 = 0U;
    __Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v9 = 0U;
    __Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v10 = 0U;
    __Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v11 = 0U;
    __Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v12 = 0U;
    __Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v13 = 0U;
    __Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v15 = 0U;
    __Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v12 = 0U;
    __Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v0 = 0U;
    __Vdly__tb_top__DOT__dut__DOT__u_cache0__DOT__pending_wdata 
        = vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__pending_wdata;
    __Vdly__tb_top__DOT__dut__DOT__u_cache0__DOT__pending_addr 
        = vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__pending_addr;
    __Vdly__tb_top__DOT__dut__DOT__u_cache0__DOT__pending_we 
        = vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__pending_we;
    __Vdly__tb_top__DOT__dut__DOT__snoop_shared_c0 
        = vlSelf->tb_top__DOT__dut__DOT__snoop_shared_c0;
    __Vdly__tb_top__DOT__dut__DOT__u_cache0__DOT__state 
        = vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__state;
    __Vdly__tb_top__DOT__dut__DOT__bus_cmd_c0 = vlSelf->tb_top__DOT__dut__DOT__bus_cmd_c0;
    __Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__tag__v8 = 0U;
    __Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v8 = 0U;
    __Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v9 = 0U;
    __Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v10 = 0U;
    __Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v11 = 0U;
    __Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v8 = 0U;
    __Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v9 = 0U;
    __Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v10 = 0U;
    __Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v11 = 0U;
    __Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v12 = 0U;
    __Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v13 = 0U;
    __Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v15 = 0U;
    __Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v12 = 0U;
    __Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v0 = 0U;
    if (vlSelf->tb_top__DOT__dut__DOT__bus_valid_w) {
        if (VL_UNLIKELY((1U == (IData)(vlSelf->tb_top__DOT__dut__DOT__bus_cmd_w)))) {
            vlSelf->tb_top__DOT__cnt_busrd = ((IData)(1U) 
                                              + vlSelf->tb_top__DOT__cnt_busrd);
            VL_WRITEF("  [BUS] BusRd   addr=0x%02x\n",
                      8,vlSelf->tb_top__DOT__dut__DOT__bus_addr_w);
        } else if (VL_UNLIKELY((2U == (IData)(vlSelf->tb_top__DOT__dut__DOT__bus_cmd_w)))) {
            VL_WRITEF("  [BUS] BusInv  addr=0x%02x\n",
                      8,vlSelf->tb_top__DOT__dut__DOT__bus_addr_w);
            vlSelf->tb_top__DOT__cnt_busInv = ((IData)(1U) 
                                               + vlSelf->tb_top__DOT__cnt_busInv);
        } else if (VL_UNLIKELY((3U == (IData)(vlSelf->tb_top__DOT__dut__DOT__bus_cmd_w)))) {
            VL_WRITEF("  [BUS] BusWB   addr=0x%02x\n",
                      8,vlSelf->tb_top__DOT__dut__DOT__bus_addr_w);
            vlSelf->tb_top__DOT__cnt_buswb = ((IData)(1U) 
                                              + vlSelf->tb_top__DOT__cnt_buswb);
        }
    }
    vlSelf->tb_top__DOT__dut__DOT__mem_valid_w = 0U;
    if (vlSelf->tb_top__DOT__dut__DOT__bus_valid_w) {
        if ((1U != (IData)(vlSelf->tb_top__DOT__dut__DOT__bus_cmd_w))) {
            if ((3U == (IData)(vlSelf->tb_top__DOT__dut__DOT__bus_cmd_w))) {
                __Vdlyvval__tb_top__DOT__dut__DOT__u_mem__DOT__mem__v0 
                    = vlSelf->tb_top__DOT__dut__DOT__bus_wdata_w[0U];
                __Vdlyvset__tb_top__DOT__dut__DOT__u_mem__DOT__mem__v0 = 1U;
                __Vdlyvdim0__tb_top__DOT__dut__DOT__u_mem__DOT__mem__v0 
                    = (0xfcU & VL_SHIFTR_III(8,8,32, (IData)(vlSelf->tb_top__DOT__dut__DOT__bus_addr_w), 2U));
                __Vdlyvval__tb_top__DOT__dut__DOT__u_mem__DOT__mem__v1 
                    = vlSelf->tb_top__DOT__dut__DOT__bus_wdata_w[1U];
                __Vdlyvdim0__tb_top__DOT__dut__DOT__u_mem__DOT__mem__v1 
                    = (0xffU & ((IData)(1U) + (0xfcU 
                                               & VL_SHIFTR_III(8,8,32, (IData)(vlSelf->tb_top__DOT__dut__DOT__bus_addr_w), 2U))));
                __Vdlyvval__tb_top__DOT__dut__DOT__u_mem__DOT__mem__v2 
                    = vlSelf->tb_top__DOT__dut__DOT__bus_wdata_w[2U];
                __Vdlyvdim0__tb_top__DOT__dut__DOT__u_mem__DOT__mem__v2 
                    = (0xffU & ((IData)(2U) + (0xfcU 
                                               & VL_SHIFTR_III(8,8,32, (IData)(vlSelf->tb_top__DOT__dut__DOT__bus_addr_w), 2U))));
                __Vdlyvval__tb_top__DOT__dut__DOT__u_mem__DOT__mem__v3 
                    = vlSelf->tb_top__DOT__dut__DOT__bus_wdata_w[3U];
                __Vdlyvdim0__tb_top__DOT__dut__DOT__u_mem__DOT__mem__v3 
                    = (0xffU & ((IData)(3U) + (0xfcU 
                                               & VL_SHIFTR_III(8,8,32, (IData)(vlSelf->tb_top__DOT__dut__DOT__bus_addr_w), 2U))));
            }
        }
        if ((1U == (IData)(vlSelf->tb_top__DOT__dut__DOT__bus_cmd_w))) {
            if ((1U & (~ (IData)(vlSelf->tb_top__DOT__dut__DOT__snoop_dirty_any)))) {
                vlSelf->tb_top__DOT__dut__DOT__mem_valid_w = 1U;
                vlSelf->tb_top__DOT__dut__DOT__mem_rdata_w[0U] 
                    = (IData)((((QData)((IData)(vlSelf->tb_top__DOT__dut__DOT__u_mem__DOT__mem
                                                [(0xffU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0xfcU 
                                                      & VL_SHIFTR_III(8,8,32, (IData)(vlSelf->tb_top__DOT__dut__DOT__bus_addr_w), 2U))))])) 
                                << 0x20U) | (QData)((IData)(
                                                            vlSelf->tb_top__DOT__dut__DOT__u_mem__DOT__mem
                                                            [
                                                            (0xfcU 
                                                             & VL_SHIFTR_III(8,8,32, (IData)(vlSelf->tb_top__DOT__dut__DOT__bus_addr_w), 2U))]))));
                vlSelf->tb_top__DOT__dut__DOT__mem_rdata_w[1U] 
                    = (IData)(((((QData)((IData)(vlSelf->tb_top__DOT__dut__DOT__u_mem__DOT__mem
                                                 [(0xffU 
                                                   & ((IData)(1U) 
                                                      + 
                                                      (0xfcU 
                                                       & VL_SHIFTR_III(8,8,32, (IData)(vlSelf->tb_top__DOT__dut__DOT__bus_addr_w), 2U))))])) 
                                 << 0x20U) | (QData)((IData)(
                                                             vlSelf->tb_top__DOT__dut__DOT__u_mem__DOT__mem
                                                             [
                                                             (0xfcU 
                                                              & VL_SHIFTR_III(8,8,32, (IData)(vlSelf->tb_top__DOT__dut__DOT__bus_addr_w), 2U))]))) 
                               >> 0x20U));
                vlSelf->tb_top__DOT__dut__DOT__mem_rdata_w[2U] 
                    = (IData)((((QData)((IData)(vlSelf->tb_top__DOT__dut__DOT__u_mem__DOT__mem
                                                [(0xffU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0xfcU 
                                                      & VL_SHIFTR_III(8,8,32, (IData)(vlSelf->tb_top__DOT__dut__DOT__bus_addr_w), 2U))))])) 
                                << 0x20U) | (QData)((IData)(
                                                            vlSelf->tb_top__DOT__dut__DOT__u_mem__DOT__mem
                                                            [
                                                            (0xffU 
                                                             & ((IData)(2U) 
                                                                + 
                                                                (0xfcU 
                                                                 & VL_SHIFTR_III(8,8,32, (IData)(vlSelf->tb_top__DOT__dut__DOT__bus_addr_w), 2U))))]))));
                vlSelf->tb_top__DOT__dut__DOT__mem_rdata_w[3U] 
                    = (IData)(((((QData)((IData)(vlSelf->tb_top__DOT__dut__DOT__u_mem__DOT__mem
                                                 [(0xffU 
                                                   & ((IData)(3U) 
                                                      + 
                                                      (0xfcU 
                                                       & VL_SHIFTR_III(8,8,32, (IData)(vlSelf->tb_top__DOT__dut__DOT__bus_addr_w), 2U))))])) 
                                 << 0x20U) | (QData)((IData)(
                                                             vlSelf->tb_top__DOT__dut__DOT__u_mem__DOT__mem
                                                             [
                                                             (0xffU 
                                                              & ((IData)(2U) 
                                                                 + 
                                                                 (0xfcU 
                                                                  & VL_SHIFTR_III(8,8,32, (IData)(vlSelf->tb_top__DOT__dut__DOT__bus_addr_w), 2U))))]))) 
                               >> 0x20U));
            }
        }
    }
    if (vlSelf->tb_top__DOT__rst) {
        __Vdly__tb_top__DOT__dut__DOT__bus_grant = 0U;
        __Vdly__tb_top__DOT__dut__DOT__u_arb__DOT__last = 0U;
    } else if ((1U & (~ (IData)((0U != ((IData)(vlSelf->tb_top__DOT__dut__DOT__bus_grant) 
                                        & (IData)(vlSelf->tb_top__DOT__dut__DOT__bus_req_w))))))) {
        vlSelf->tb_top__DOT__dut__DOT__u_arb__DOT__arb__DOT__i = 3U;
        __Vdly__tb_top__DOT__dut__DOT__bus_grant = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_arb__DOT__arb__DOT__j 
            = (1U & ((IData)(1U) + (IData)(vlSelf->tb_top__DOT__dut__DOT__u_arb__DOT__last)));
        if ((1U & (((IData)(vlSelf->tb_top__DOT__dut__DOT__bus_req_w) 
                    >> (1U & vlSelf->tb_top__DOT__dut__DOT__u_arb__DOT__arb__DOT__j)) 
                   & (~ (IData)((0U != (IData)(vlSelf->tb_top__DOT__dut__DOT__bus_grant))))))) {
            __Vdly__tb_top__DOT__dut__DOT__bus_grant 
                = (3U & VL_SHIFTL_III(2,32,32, (IData)(1U), vlSelf->tb_top__DOT__dut__DOT__u_arb__DOT__arb__DOT__j));
            __Vdly__tb_top__DOT__dut__DOT__u_arb__DOT__last 
                = (1U & vlSelf->tb_top__DOT__dut__DOT__u_arb__DOT__arb__DOT__j);
        }
        vlSelf->tb_top__DOT__dut__DOT__u_arb__DOT__arb__DOT__j 
            = (1U & ((IData)(2U) + (IData)(vlSelf->tb_top__DOT__dut__DOT__u_arb__DOT__last)));
        if ((1U & (((IData)(vlSelf->tb_top__DOT__dut__DOT__bus_req_w) 
                    >> (1U & vlSelf->tb_top__DOT__dut__DOT__u_arb__DOT__arb__DOT__j)) 
                   & (~ (IData)((0U != (IData)(vlSelf->tb_top__DOT__dut__DOT__bus_grant))))))) {
            __Vdly__tb_top__DOT__dut__DOT__bus_grant 
                = (3U & VL_SHIFTL_III(2,32,32, (IData)(1U), vlSelf->tb_top__DOT__dut__DOT__u_arb__DOT__arb__DOT__j));
            __Vdly__tb_top__DOT__dut__DOT__u_arb__DOT__last 
                = (1U & vlSelf->tb_top__DOT__dut__DOT__u_arb__DOT__arb__DOT__j);
        }
    }
    if (vlSelf->tb_top__DOT__rst) {
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__i = 8U;
        __Vdly__tb_top__DOT__dut__DOT__u_cache1__DOT__state = 0U;
        vlSelf->tb_top__DOT__c1_ack = 0U;
        vlSelf->tb_top__DOT__dut__DOT____Vcellout__u_cache1__bus_req = 0U;
        vlSelf->tb_top__DOT__dut__DOT__bus_drive_c1 = 0U;
        __Vdly__tb_top__DOT__dut__DOT__snoop_shared_c1 = 0U;
        vlSelf->tb_top__DOT__dut__DOT__snoop_dirty_c1 = 0U;
        vlSelf->tb_top__DOT__dut__DOT__snoop_rdata_c1[0U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__snoop_rdata_c1[1U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__snoop_rdata_c1[2U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__snoop_rdata_c1[3U] = 0U;
        __Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v0 = 1U;
    } else {
        vlSelf->tb_top__DOT__c1_ack = 0U;
        __Vdly__tb_top__DOT__dut__DOT__snoop_shared_c1 = 0U;
        vlSelf->tb_top__DOT__dut__DOT__snoop_dirty_c1 = 0U;
        vlSelf->tb_top__DOT__dut__DOT__bus_drive_c1 = 0U;
        if (vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__snoop_hit) {
            if ((1U == (IData)(vlSelf->tb_top__DOT__dut__DOT__bus_cmd_w))) {
                if ((3U == vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi
                     [vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__snoop_index])) {
                    vlSelf->tb_top__DOT__dut__DOT__snoop_rdata_c1[0U] 
                        = vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data
                        [vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__snoop_index][0U];
                    vlSelf->tb_top__DOT__dut__DOT__snoop_rdata_c1[1U] 
                        = vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data
                        [vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__snoop_index][1U];
                    vlSelf->tb_top__DOT__dut__DOT__snoop_rdata_c1[2U] 
                        = vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data
                        [vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__snoop_index][2U];
                    vlSelf->tb_top__DOT__dut__DOT__snoop_rdata_c1[3U] 
                        = vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data
                        [vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__snoop_index][3U];
                    vlSelf->tb_top__DOT__dut__DOT__snoop_dirty_c1 = 1U;
                    __Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v8 = 1U;
                    __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v8 
                        = vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__snoop_index;
                } else {
                    if ((2U == vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi
                         [vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__snoop_index])) {
                        __Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v9 = 1U;
                        __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v9 
                            = vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__snoop_index;
                    }
                    __Vdly__tb_top__DOT__dut__DOT__snoop_shared_c1 = 1U;
                }
            } else if ((2U == (IData)(vlSelf->tb_top__DOT__dut__DOT__bus_cmd_w))) {
                __Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v10 = 1U;
                __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v10 
                    = vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__snoop_index;
            }
        }
        if ((0U == (IData)(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__state))) {
            if (vlSelf->tb_top__DOT__c1_req) {
                __Vdly__tb_top__DOT__dut__DOT__u_cache1__DOT__pending_we 
                    = vlSelf->tb_top__DOT__c1_we;
                __Vdly__tb_top__DOT__dut__DOT__u_cache1__DOT__pending_addr 
                    = vlSelf->tb_top__DOT__c1_addr;
                __Vdly__tb_top__DOT__dut__DOT__u_cache1__DOT__pending_wdata 
                    = vlSelf->tb_top__DOT__c1_wdata;
                if (vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__hit) {
                    __Vdly__tb_top__DOT__dut__DOT__u_cache1__DOT__state = 1U;
                } else if ((3U == vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi
                            [vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__cpu_index])) {
                    __Vdly__tb_top__DOT__dut__DOT__u_cache1__DOT__state = 5U;
                    vlSelf->tb_top__DOT__dut__DOT____Vcellout__u_cache1__bus_req = 1U;
                } else {
                    __Vdly__tb_top__DOT__dut__DOT__u_cache1__DOT__state = 2U;
                    vlSelf->tb_top__DOT__dut__DOT____Vcellout__u_cache1__bus_req = 1U;
                }
            }
        } else if ((1U == (IData)(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__state))) {
            if (vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__pending_we) {
                if ((1U | (((3U == vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi
                             [([&]() {
                                            __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__148__a 
                                                = vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__pending_addr;
                                            __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__148__Vfuncout 
                                                = (7U 
                                                   & ((IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__148__a) 
                                                      >> 2U));
                                        }(), (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__148__Vfuncout))]) 
                            | (2U == vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi
                               [([&]() {
                                            __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__149__a 
                                                = vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__pending_addr;
                                            __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__149__Vfuncout 
                                                = (7U 
                                                   & ((IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__149__a) 
                                                      >> 2U));
                                        }(), (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__149__Vfuncout))])) 
                           | (1U == vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi
                              [([&]() {
                                        __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__150__a 
                                            = vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__pending_addr;
                                        __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__150__Vfuncout 
                                            = (7U & 
                                               ((IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__150__a) 
                                                >> 2U));
                                    }(), (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__150__Vfuncout))])))) {
                    if ((3U == vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi
                         [([&]() {
                                    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__151__a 
                                        = vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__pending_addr;
                                    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__151__Vfuncout 
                                        = (7U & ((IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__151__a) 
                                                 >> 2U));
                                }(), (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__151__Vfuncout))])) {
                        __Vdlyvval__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v8 
                            = vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__pending_wdata;
                        __Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v8 = 1U;
                        __Vdlyvlsb__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v8 
                            = (0x7fU & VL_SHIFTL_III(7,32,32, 
                                                     VL_EXTEND_II(32,2, 
                                                                  ([&]() {
                                            __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__153__a 
                                                = vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__pending_addr;
                                            __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__153__Vfuncout 
                                                = (3U 
                                                   & (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__153__a));
                                        }(), (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__153__Vfuncout))), 5U));
                        __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v8 
                            = ([&]() {
                                __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__152__a 
                                    = vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__pending_addr;
                                __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__152__Vfuncout 
                                    = (7U & ((IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__152__a) 
                                             >> 2U));
                            }(), (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__152__Vfuncout));
                        vlSelf->tb_top__DOT__c1_ack = 1U;
                        __Vdly__tb_top__DOT__dut__DOT__u_cache1__DOT__state = 0U;
                    } else if ((2U == vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi
                                [([&]() {
                                    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__154__a 
                                        = vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__pending_addr;
                                    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__154__Vfuncout 
                                        = (7U & ((IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__154__a) 
                                                 >> 2U));
                                }(), (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__154__Vfuncout))])) {
                        __Vdlyvval__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v9 
                            = vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__pending_wdata;
                        __Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v9 = 1U;
                        __Vdlyvlsb__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v9 
                            = (0x7fU & VL_SHIFTL_III(7,32,32, 
                                                     VL_EXTEND_II(32,2, 
                                                                  ([&]() {
                                            __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__156__a 
                                                = vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__pending_addr;
                                            __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__156__Vfuncout 
                                                = (3U 
                                                   & (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__156__a));
                                        }(), (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__156__Vfuncout))), 5U));
                        __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v9 
                            = ([&]() {
                                __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__155__a 
                                    = vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__pending_addr;
                                __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__155__Vfuncout 
                                    = (7U & ((IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__155__a) 
                                             >> 2U));
                            }(), (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__155__Vfuncout));
                        vlSelf->tb_top__DOT__c1_ack = 1U;
                        __Vdly__tb_top__DOT__dut__DOT__u_cache1__DOT__state = 0U;
                        __Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v11 = 1U;
                        __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v11 
                            = ([&]() {
                                __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__157__a 
                                    = vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__pending_addr;
                                __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__157__Vfuncout 
                                    = (7U & ((IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__157__a) 
                                             >> 2U));
                            }(), (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__157__Vfuncout));
                    } else if ((1U == vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi
                                [([&]() {
                                    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__158__a 
                                        = vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__pending_addr;
                                    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__158__Vfuncout 
                                        = (7U & ((IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__158__a) 
                                                 >> 2U));
                                }(), (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__158__Vfuncout))])) {
                        vlSelf->tb_top__DOT__dut__DOT____Vcellout__u_cache1__bus_req = 1U;
                        __Vdly__tb_top__DOT__dut__DOT__u_cache1__DOT__state = 2U;
                    } else {
                        __Vdly__tb_top__DOT__dut__DOT__u_cache1__DOT__state = 0U;
                    }
                }
            } else {
                vlSelf->tb_top__DOT__c1_rdata = VL_SEL_IWII(128, 
                                                            vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data
                                                            [
                                                            ([&]() {
                            __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__159__a 
                                = vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__pending_addr;
                            __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__159__Vfuncout 
                                = (7U & ((IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__159__a) 
                                         >> 2U));
                        }(), (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__159__Vfuncout))], 
                                                            (0x7fU 
                                                             & VL_SHIFTL_III(7,32,32, 
                                                                             VL_EXTEND_II(32,2, 
                                                                                ([&]() {
                                        __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__160__a 
                                            = vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__pending_addr;
                                        __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__160__Vfuncout 
                                            = (3U & (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__160__a));
                                    }(), (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__160__Vfuncout))), 5U)), 0x20U);
                vlSelf->tb_top__DOT__c1_ack = 1U;
                __Vdly__tb_top__DOT__dut__DOT__u_cache1__DOT__state = 0U;
            }
        } else if ((5U == (IData)(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__state))) {
            if ((2U & (IData)(vlSelf->tb_top__DOT__dut__DOT__bus_grant))) {
                vlSelf->tb_top__DOT__dut__DOT__bus_drive_c1 = 1U;
                __Vdly__tb_top__DOT__dut__DOT__bus_cmd_c1 = 3U;
                vlSelf->tb_top__DOT__dut__DOT__bus_addr_c1 
                    = ((vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__tag
                        [([&]() {
                                __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__161__a 
                                    = vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__pending_addr;
                                __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__161__Vfuncout 
                                    = (7U & ((IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__161__a) 
                                             >> 2U));
                            }(), (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__161__Vfuncout))] 
                        << 5U) | (([&]() {
                                __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__162__a 
                                    = vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__pending_addr;
                                __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__162__Vfuncout 
                                    = (7U & ((IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__162__a) 
                                             >> 2U));
                            }(), (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__162__Vfuncout)) 
                                  << 2U));
                __Vdly__tb_top__DOT__dut__DOT__u_cache1__DOT__state = 6U;
                VL_ASSIGN_W(128,vlSelf->tb_top__DOT__dut__DOT__bus_data_c1, 
                            vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data
                            [([&]() {
                            __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__163__a 
                                = vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__pending_addr;
                            __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__163__Vfuncout 
                                = (7U & ((IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__163__a) 
                                         >> 2U));
                        }(), (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__163__Vfuncout))]);
                __Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v12 = 1U;
                __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v12 
                    = ([&]() {
                        __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__164__a 
                            = vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__pending_addr;
                        __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__164__Vfuncout 
                            = (7U & ((IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__164__a) 
                                     >> 2U));
                    }(), (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__164__Vfuncout));
            }
        } else if ((6U == (IData)(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__state))) {
            vlSelf->tb_top__DOT__dut__DOT__bus_drive_c1 = 0U;
            vlSelf->tb_top__DOT__dut__DOT____Vcellout__u_cache1__bus_req = 1U;
            __Vdly__tb_top__DOT__dut__DOT__u_cache1__DOT__state = 2U;
        } else if ((2U == (IData)(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__state))) {
            if ((2U & (IData)(vlSelf->tb_top__DOT__dut__DOT__bus_grant))) {
                vlSelf->tb_top__DOT__dut__DOT__bus_drive_c1 = 1U;
                if (((IData)(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__pending_we) 
                     & (1U == vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi
                        [([&]() {
                                    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__165__a 
                                        = vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__pending_addr;
                                    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__165__Vfuncout 
                                        = (7U & ((IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__165__a) 
                                                 >> 2U));
                                }(), (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__165__Vfuncout))]))) {
                    __Vdly__tb_top__DOT__dut__DOT__bus_cmd_c1 = 2U;
                    vlSelf->tb_top__DOT__dut__DOT__bus_addr_c1 
                        = vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__pending_addr;
                    vlSelf->tb_top__DOT__dut__DOT__bus_data_c1[0U] = 0U;
                    vlSelf->tb_top__DOT__dut__DOT__bus_data_c1[1U] = 0U;
                    vlSelf->tb_top__DOT__dut__DOT__bus_data_c1[2U] = 0U;
                    vlSelf->tb_top__DOT__dut__DOT__bus_data_c1[3U] = 0U;
                } else {
                    __Vdly__tb_top__DOT__dut__DOT__bus_cmd_c1 = 1U;
                    vlSelf->tb_top__DOT__dut__DOT__bus_addr_c1 
                        = vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__pending_addr;
                    vlSelf->tb_top__DOT__dut__DOT__bus_data_c1[0U] = 0U;
                    vlSelf->tb_top__DOT__dut__DOT__bus_data_c1[1U] = 0U;
                    vlSelf->tb_top__DOT__dut__DOT__bus_data_c1[2U] = 0U;
                    vlSelf->tb_top__DOT__dut__DOT__bus_data_c1[3U] = 0U;
                }
                __Vdly__tb_top__DOT__dut__DOT__u_cache1__DOT__state = 3U;
            }
        } else if ((3U == (IData)(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__state))) {
            vlSelf->tb_top__DOT__dut__DOT__bus_drive_c1 = 0U;
            vlSelf->tb_top__DOT__dut__DOT____Vcellout__u_cache1__bus_req = 0U;
            if ((2U == (IData)(vlSelf->tb_top__DOT__dut__DOT__bus_cmd_c1))) {
                __Vdlyvval__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v10 
                    = vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__pending_wdata;
                __Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v10 = 1U;
                __Vdlyvlsb__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v10 
                    = (0x7fU & VL_SHIFTL_III(7,32,32, 
                                             VL_EXTEND_II(32,2, 
                                                          ([&]() {
                                    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__167__a 
                                        = vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__pending_addr;
                                    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__167__Vfuncout 
                                        = (3U & (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__167__a));
                                }(), (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__167__Vfuncout))), 5U));
                __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v10 
                    = ([&]() {
                        __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__166__a 
                            = vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__pending_addr;
                        __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__166__Vfuncout 
                            = (7U & ((IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__166__a) 
                                     >> 2U));
                    }(), (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__166__Vfuncout));
                vlSelf->tb_top__DOT__c1_ack = 1U;
                __Vdly__tb_top__DOT__dut__DOT__u_cache1__DOT__state = 0U;
                __Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v13 = 1U;
                __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v13 
                    = ([&]() {
                        __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__168__a 
                            = vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__pending_addr;
                        __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__168__Vfuncout 
                            = (7U & ((IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__168__a) 
                                     >> 2U));
                    }(), (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__168__Vfuncout));
            } else {
                __Vdly__tb_top__DOT__dut__DOT__u_cache1__DOT__state = 4U;
            }
        } else if ((4U == (IData)(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__state))) {
            __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_tag__169__a 
                = vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__pending_addr;
            __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_tag__169__Vfuncout 
                = (7U & ((IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_tag__169__a) 
                         >> 5U));
            __Vdlyvval__tb_top__DOT__dut__DOT__u_cache1__DOT__tag__v8 
                = __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_tag__169__Vfuncout;
            __Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__tag__v8 = 1U;
            __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache1__DOT__tag__v8 
                = ([&]() {
                    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__170__a 
                        = vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__pending_addr;
                    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__170__Vfuncout 
                        = (7U & ((IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__170__a) 
                                 >> 2U));
                }(), (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__170__Vfuncout));
            vlSelf->tb_top__DOT__c1_ack = 1U;
            __Vdly__tb_top__DOT__dut__DOT__u_cache1__DOT__state = 0U;
            __Vdlyvval__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v11[0U] 
                = vlSelf->tb_top__DOT__dut__DOT__fill_data[0U];
            __Vdlyvval__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v11[1U] 
                = vlSelf->tb_top__DOT__dut__DOT__fill_data[1U];
            __Vdlyvval__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v11[2U] 
                = vlSelf->tb_top__DOT__dut__DOT__fill_data[2U];
            __Vdlyvval__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v11[3U] 
                = vlSelf->tb_top__DOT__dut__DOT__fill_data[3U];
            __Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v11 = 1U;
            __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v11 
                = ([&]() {
                    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__171__a 
                        = vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__pending_addr;
                    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__171__Vfuncout 
                        = (7U & ((IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__171__a) 
                                 >> 2U));
                }(), (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__171__Vfuncout));
            if (vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__pending_we) {
                __Vdlyvval__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v12 
                    = vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__pending_wdata;
                __Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v12 = 1U;
                __Vdlyvlsb__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v12 
                    = (0x7fU & VL_SHIFTL_III(7,32,32, 
                                             VL_EXTEND_II(32,2, 
                                                          ([&]() {
                                    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__173__a 
                                        = vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__pending_addr;
                                    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__173__Vfuncout 
                                        = (3U & (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__173__a));
                                }(), (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__173__Vfuncout))), 5U));
                __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v12 
                    = ([&]() {
                        __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__172__a 
                            = vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__pending_addr;
                        __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__172__Vfuncout 
                            = (7U & ((IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__172__a) 
                                     >> 2U));
                    }(), (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__172__Vfuncout));
                __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v14 
                    = ([&]() {
                        __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__174__a 
                            = vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__pending_addr;
                        __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__174__Vfuncout 
                            = (7U & ((IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__174__a) 
                                     >> 2U));
                    }(), (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__174__Vfuncout));
            } else {
                __Vdlyvval__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v15 
                    = ((IData)(vlSelf->tb_top__DOT__dut__DOT__snoop_shared_c1)
                        ? 1U : 2U);
                __Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v15 = 1U;
                __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v15 
                    = ([&]() {
                        __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__175__a 
                            = vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__pending_addr;
                        __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__175__Vfuncout 
                            = (7U & ((IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__175__a) 
                                     >> 2U));
                    }(), (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__175__Vfuncout));
                vlSelf->tb_top__DOT__c1_rdata = VL_SEL_IWII(128, vlSelf->tb_top__DOT__dut__DOT__fill_data, 
                                                            (0x7fU 
                                                             & VL_SHIFTL_III(7,32,32, 
                                                                             VL_EXTEND_II(32,2, 
                                                                                ([&]() {
                                        __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__176__a 
                                            = vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__pending_addr;
                                        __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__176__Vfuncout 
                                            = (3U & (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__176__a));
                                    }(), (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__176__Vfuncout))), 5U)), 0x20U);
            }
        }
    }
    if (vlSelf->tb_top__DOT__rst) {
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__i = 8U;
        __Vdly__tb_top__DOT__dut__DOT__u_cache0__DOT__state = 0U;
        vlSelf->tb_top__DOT__c0_ack = 0U;
        vlSelf->tb_top__DOT__dut__DOT____Vcellout__u_cache0__bus_req = 0U;
        vlSelf->tb_top__DOT__dut__DOT__bus_drive_c0 = 0U;
        __Vdly__tb_top__DOT__dut__DOT__snoop_shared_c0 = 0U;
        vlSelf->tb_top__DOT__dut__DOT__snoop_dirty_c0 = 0U;
        vlSelf->tb_top__DOT__dut__DOT__snoop_rdata_c0[0U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__snoop_rdata_c0[1U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__snoop_rdata_c0[2U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__snoop_rdata_c0[3U] = 0U;
        __Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v0 = 1U;
    } else {
        vlSelf->tb_top__DOT__c0_ack = 0U;
        __Vdly__tb_top__DOT__dut__DOT__snoop_shared_c0 = 0U;
        vlSelf->tb_top__DOT__dut__DOT__snoop_dirty_c0 = 0U;
        vlSelf->tb_top__DOT__dut__DOT__bus_drive_c0 = 0U;
        if (vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__snoop_hit) {
            if ((1U == (IData)(vlSelf->tb_top__DOT__dut__DOT__bus_cmd_w))) {
                if ((3U == vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi
                     [vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__snoop_index])) {
                    vlSelf->tb_top__DOT__dut__DOT__snoop_rdata_c0[0U] 
                        = vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data
                        [vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__snoop_index][0U];
                    vlSelf->tb_top__DOT__dut__DOT__snoop_rdata_c0[1U] 
                        = vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data
                        [vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__snoop_index][1U];
                    vlSelf->tb_top__DOT__dut__DOT__snoop_rdata_c0[2U] 
                        = vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data
                        [vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__snoop_index][2U];
                    vlSelf->tb_top__DOT__dut__DOT__snoop_rdata_c0[3U] 
                        = vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data
                        [vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__snoop_index][3U];
                    vlSelf->tb_top__DOT__dut__DOT__snoop_dirty_c0 = 1U;
                    __Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v8 = 1U;
                    __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v8 
                        = vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__snoop_index;
                } else {
                    if ((2U == vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi
                         [vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__snoop_index])) {
                        __Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v9 = 1U;
                        __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v9 
                            = vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__snoop_index;
                    }
                    __Vdly__tb_top__DOT__dut__DOT__snoop_shared_c0 = 1U;
                }
            } else if ((2U == (IData)(vlSelf->tb_top__DOT__dut__DOT__bus_cmd_w))) {
                __Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v10 = 1U;
                __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v10 
                    = vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__snoop_index;
            }
        }
        if ((0U == (IData)(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__state))) {
            if (vlSelf->tb_top__DOT__c0_req) {
                __Vdly__tb_top__DOT__dut__DOT__u_cache0__DOT__pending_we 
                    = vlSelf->tb_top__DOT__c0_we;
                __Vdly__tb_top__DOT__dut__DOT__u_cache0__DOT__pending_addr 
                    = vlSelf->tb_top__DOT__c0_addr;
                __Vdly__tb_top__DOT__dut__DOT__u_cache0__DOT__pending_wdata 
                    = vlSelf->tb_top__DOT__c0_wdata;
                if (vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__hit) {
                    __Vdly__tb_top__DOT__dut__DOT__u_cache0__DOT__state = 1U;
                } else if ((3U == vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi
                            [vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__cpu_index])) {
                    __Vdly__tb_top__DOT__dut__DOT__u_cache0__DOT__state = 5U;
                    vlSelf->tb_top__DOT__dut__DOT____Vcellout__u_cache0__bus_req = 1U;
                } else {
                    __Vdly__tb_top__DOT__dut__DOT__u_cache0__DOT__state = 2U;
                    vlSelf->tb_top__DOT__dut__DOT____Vcellout__u_cache0__bus_req = 1U;
                }
            }
        } else if ((1U == (IData)(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__state))) {
            if (vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__pending_we) {
                if ((1U | (((3U == vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi
                             [([&]() {
                                            __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__114__a 
                                                = vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__pending_addr;
                                            __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__114__Vfuncout 
                                                = (7U 
                                                   & ((IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__114__a) 
                                                      >> 2U));
                                        }(), (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__114__Vfuncout))]) 
                            | (2U == vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi
                               [([&]() {
                                            __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__115__a 
                                                = vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__pending_addr;
                                            __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__115__Vfuncout 
                                                = (7U 
                                                   & ((IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__115__a) 
                                                      >> 2U));
                                        }(), (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__115__Vfuncout))])) 
                           | (1U == vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi
                              [([&]() {
                                        __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__116__a 
                                            = vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__pending_addr;
                                        __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__116__Vfuncout 
                                            = (7U & 
                                               ((IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__116__a) 
                                                >> 2U));
                                    }(), (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__116__Vfuncout))])))) {
                    if ((3U == vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi
                         [([&]() {
                                    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__117__a 
                                        = vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__pending_addr;
                                    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__117__Vfuncout 
                                        = (7U & ((IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__117__a) 
                                                 >> 2U));
                                }(), (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__117__Vfuncout))])) {
                        __Vdlyvval__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v8 
                            = vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__pending_wdata;
                        __Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v8 = 1U;
                        __Vdlyvlsb__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v8 
                            = (0x7fU & VL_SHIFTL_III(7,32,32, 
                                                     VL_EXTEND_II(32,2, 
                                                                  ([&]() {
                                            __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__119__a 
                                                = vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__pending_addr;
                                            __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__119__Vfuncout 
                                                = (3U 
                                                   & (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__119__a));
                                        }(), (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__119__Vfuncout))), 5U));
                        __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v8 
                            = ([&]() {
                                __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__118__a 
                                    = vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__pending_addr;
                                __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__118__Vfuncout 
                                    = (7U & ((IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__118__a) 
                                             >> 2U));
                            }(), (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__118__Vfuncout));
                        vlSelf->tb_top__DOT__c0_ack = 1U;
                        __Vdly__tb_top__DOT__dut__DOT__u_cache0__DOT__state = 0U;
                    } else if ((2U == vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi
                                [([&]() {
                                    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__120__a 
                                        = vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__pending_addr;
                                    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__120__Vfuncout 
                                        = (7U & ((IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__120__a) 
                                                 >> 2U));
                                }(), (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__120__Vfuncout))])) {
                        __Vdlyvval__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v9 
                            = vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__pending_wdata;
                        __Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v9 = 1U;
                        __Vdlyvlsb__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v9 
                            = (0x7fU & VL_SHIFTL_III(7,32,32, 
                                                     VL_EXTEND_II(32,2, 
                                                                  ([&]() {
                                            __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__122__a 
                                                = vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__pending_addr;
                                            __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__122__Vfuncout 
                                                = (3U 
                                                   & (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__122__a));
                                        }(), (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__122__Vfuncout))), 5U));
                        __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v9 
                            = ([&]() {
                                __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__121__a 
                                    = vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__pending_addr;
                                __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__121__Vfuncout 
                                    = (7U & ((IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__121__a) 
                                             >> 2U));
                            }(), (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__121__Vfuncout));
                        vlSelf->tb_top__DOT__c0_ack = 1U;
                        __Vdly__tb_top__DOT__dut__DOT__u_cache0__DOT__state = 0U;
                        __Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v11 = 1U;
                        __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v11 
                            = ([&]() {
                                __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__123__a 
                                    = vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__pending_addr;
                                __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__123__Vfuncout 
                                    = (7U & ((IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__123__a) 
                                             >> 2U));
                            }(), (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__123__Vfuncout));
                    } else if ((1U == vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi
                                [([&]() {
                                    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__124__a 
                                        = vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__pending_addr;
                                    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__124__Vfuncout 
                                        = (7U & ((IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__124__a) 
                                                 >> 2U));
                                }(), (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__124__Vfuncout))])) {
                        vlSelf->tb_top__DOT__dut__DOT____Vcellout__u_cache0__bus_req = 1U;
                        __Vdly__tb_top__DOT__dut__DOT__u_cache0__DOT__state = 2U;
                    } else {
                        __Vdly__tb_top__DOT__dut__DOT__u_cache0__DOT__state = 0U;
                    }
                }
            } else {
                vlSelf->tb_top__DOT__c0_rdata = VL_SEL_IWII(128, 
                                                            vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data
                                                            [
                                                            ([&]() {
                            __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__125__a 
                                = vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__pending_addr;
                            __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__125__Vfuncout 
                                = (7U & ((IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__125__a) 
                                         >> 2U));
                        }(), (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__125__Vfuncout))], 
                                                            (0x7fU 
                                                             & VL_SHIFTL_III(7,32,32, 
                                                                             VL_EXTEND_II(32,2, 
                                                                                ([&]() {
                                        __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__126__a 
                                            = vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__pending_addr;
                                        __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__126__Vfuncout 
                                            = (3U & (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__126__a));
                                    }(), (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__126__Vfuncout))), 5U)), 0x20U);
                vlSelf->tb_top__DOT__c0_ack = 1U;
                __Vdly__tb_top__DOT__dut__DOT__u_cache0__DOT__state = 0U;
            }
        } else if ((5U == (IData)(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__state))) {
            if ((1U & (IData)(vlSelf->tb_top__DOT__dut__DOT__bus_grant))) {
                vlSelf->tb_top__DOT__dut__DOT__bus_drive_c0 = 1U;
                __Vdly__tb_top__DOT__dut__DOT__bus_cmd_c0 = 3U;
                vlSelf->tb_top__DOT__dut__DOT__bus_addr_c0 
                    = ((vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__tag
                        [([&]() {
                                __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__127__a 
                                    = vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__pending_addr;
                                __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__127__Vfuncout 
                                    = (7U & ((IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__127__a) 
                                             >> 2U));
                            }(), (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__127__Vfuncout))] 
                        << 5U) | (([&]() {
                                __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__128__a 
                                    = vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__pending_addr;
                                __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__128__Vfuncout 
                                    = (7U & ((IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__128__a) 
                                             >> 2U));
                            }(), (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__128__Vfuncout)) 
                                  << 2U));
                __Vdly__tb_top__DOT__dut__DOT__u_cache0__DOT__state = 6U;
                VL_ASSIGN_W(128,vlSelf->tb_top__DOT__dut__DOT__bus_data_c0, 
                            vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data
                            [([&]() {
                            __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__129__a 
                                = vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__pending_addr;
                            __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__129__Vfuncout 
                                = (7U & ((IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__129__a) 
                                         >> 2U));
                        }(), (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__129__Vfuncout))]);
                __Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v12 = 1U;
                __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v12 
                    = ([&]() {
                        __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__130__a 
                            = vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__pending_addr;
                        __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__130__Vfuncout 
                            = (7U & ((IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__130__a) 
                                     >> 2U));
                    }(), (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__130__Vfuncout));
            }
        } else if ((6U == (IData)(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__state))) {
            vlSelf->tb_top__DOT__dut__DOT__bus_drive_c0 = 0U;
            vlSelf->tb_top__DOT__dut__DOT____Vcellout__u_cache0__bus_req = 1U;
            __Vdly__tb_top__DOT__dut__DOT__u_cache0__DOT__state = 2U;
        } else if ((2U == (IData)(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__state))) {
            if ((1U & (IData)(vlSelf->tb_top__DOT__dut__DOT__bus_grant))) {
                vlSelf->tb_top__DOT__dut__DOT__bus_drive_c0 = 1U;
                if (((IData)(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__pending_we) 
                     & (1U == vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi
                        [([&]() {
                                    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__131__a 
                                        = vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__pending_addr;
                                    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__131__Vfuncout 
                                        = (7U & ((IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__131__a) 
                                                 >> 2U));
                                }(), (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__131__Vfuncout))]))) {
                    __Vdly__tb_top__DOT__dut__DOT__bus_cmd_c0 = 2U;
                    vlSelf->tb_top__DOT__dut__DOT__bus_addr_c0 
                        = vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__pending_addr;
                    vlSelf->tb_top__DOT__dut__DOT__bus_data_c0[0U] = 0U;
                    vlSelf->tb_top__DOT__dut__DOT__bus_data_c0[1U] = 0U;
                    vlSelf->tb_top__DOT__dut__DOT__bus_data_c0[2U] = 0U;
                    vlSelf->tb_top__DOT__dut__DOT__bus_data_c0[3U] = 0U;
                } else {
                    __Vdly__tb_top__DOT__dut__DOT__bus_cmd_c0 = 1U;
                    vlSelf->tb_top__DOT__dut__DOT__bus_addr_c0 
                        = vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__pending_addr;
                    vlSelf->tb_top__DOT__dut__DOT__bus_data_c0[0U] = 0U;
                    vlSelf->tb_top__DOT__dut__DOT__bus_data_c0[1U] = 0U;
                    vlSelf->tb_top__DOT__dut__DOT__bus_data_c0[2U] = 0U;
                    vlSelf->tb_top__DOT__dut__DOT__bus_data_c0[3U] = 0U;
                }
                __Vdly__tb_top__DOT__dut__DOT__u_cache0__DOT__state = 3U;
            }
        } else if ((3U == (IData)(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__state))) {
            vlSelf->tb_top__DOT__dut__DOT__bus_drive_c0 = 0U;
            vlSelf->tb_top__DOT__dut__DOT____Vcellout__u_cache0__bus_req = 0U;
            if ((2U == (IData)(vlSelf->tb_top__DOT__dut__DOT__bus_cmd_c0))) {
                __Vdlyvval__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v10 
                    = vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__pending_wdata;
                __Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v10 = 1U;
                __Vdlyvlsb__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v10 
                    = (0x7fU & VL_SHIFTL_III(7,32,32, 
                                             VL_EXTEND_II(32,2, 
                                                          ([&]() {
                                    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__133__a 
                                        = vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__pending_addr;
                                    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__133__Vfuncout 
                                        = (3U & (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__133__a));
                                }(), (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__133__Vfuncout))), 5U));
                __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v10 
                    = ([&]() {
                        __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__132__a 
                            = vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__pending_addr;
                        __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__132__Vfuncout 
                            = (7U & ((IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__132__a) 
                                     >> 2U));
                    }(), (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__132__Vfuncout));
                vlSelf->tb_top__DOT__c0_ack = 1U;
                __Vdly__tb_top__DOT__dut__DOT__u_cache0__DOT__state = 0U;
                __Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v13 = 1U;
                __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v13 
                    = ([&]() {
                        __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__134__a 
                            = vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__pending_addr;
                        __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__134__Vfuncout 
                            = (7U & ((IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__134__a) 
                                     >> 2U));
                    }(), (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__134__Vfuncout));
            } else {
                __Vdly__tb_top__DOT__dut__DOT__u_cache0__DOT__state = 4U;
            }
        } else if ((4U == (IData)(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__state))) {
            __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_tag__135__a 
                = vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__pending_addr;
            __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_tag__135__Vfuncout 
                = (7U & ((IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_tag__135__a) 
                         >> 5U));
            __Vdlyvval__tb_top__DOT__dut__DOT__u_cache0__DOT__tag__v8 
                = __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_tag__135__Vfuncout;
            __Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__tag__v8 = 1U;
            __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache0__DOT__tag__v8 
                = ([&]() {
                    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__136__a 
                        = vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__pending_addr;
                    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__136__Vfuncout 
                        = (7U & ((IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__136__a) 
                                 >> 2U));
                }(), (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__136__Vfuncout));
            vlSelf->tb_top__DOT__c0_ack = 1U;
            __Vdly__tb_top__DOT__dut__DOT__u_cache0__DOT__state = 0U;
            __Vdlyvval__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v11[0U] 
                = vlSelf->tb_top__DOT__dut__DOT__fill_data[0U];
            __Vdlyvval__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v11[1U] 
                = vlSelf->tb_top__DOT__dut__DOT__fill_data[1U];
            __Vdlyvval__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v11[2U] 
                = vlSelf->tb_top__DOT__dut__DOT__fill_data[2U];
            __Vdlyvval__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v11[3U] 
                = vlSelf->tb_top__DOT__dut__DOT__fill_data[3U];
            __Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v11 = 1U;
            __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v11 
                = ([&]() {
                    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__137__a 
                        = vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__pending_addr;
                    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__137__Vfuncout 
                        = (7U & ((IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__137__a) 
                                 >> 2U));
                }(), (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__137__Vfuncout));
            if (vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__pending_we) {
                __Vdlyvval__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v12 
                    = vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__pending_wdata;
                __Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v12 = 1U;
                __Vdlyvlsb__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v12 
                    = (0x7fU & VL_SHIFTL_III(7,32,32, 
                                             VL_EXTEND_II(32,2, 
                                                          ([&]() {
                                    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__139__a 
                                        = vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__pending_addr;
                                    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__139__Vfuncout 
                                        = (3U & (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__139__a));
                                }(), (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__139__Vfuncout))), 5U));
                __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v12 
                    = ([&]() {
                        __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__138__a 
                            = vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__pending_addr;
                        __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__138__Vfuncout 
                            = (7U & ((IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__138__a) 
                                     >> 2U));
                    }(), (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__138__Vfuncout));
                __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v14 
                    = ([&]() {
                        __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__140__a 
                            = vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__pending_addr;
                        __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__140__Vfuncout 
                            = (7U & ((IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__140__a) 
                                     >> 2U));
                    }(), (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__140__Vfuncout));
            } else {
                __Vdlyvval__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v15 
                    = ((IData)(vlSelf->tb_top__DOT__dut__DOT__snoop_shared_c0)
                        ? 1U : 2U);
                __Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v15 = 1U;
                __Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v15 
                    = ([&]() {
                        __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__141__a 
                            = vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__pending_addr;
                        __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__141__Vfuncout 
                            = (7U & ((IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__141__a) 
                                     >> 2U));
                    }(), (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__141__Vfuncout));
                vlSelf->tb_top__DOT__c0_rdata = VL_SEL_IWII(128, vlSelf->tb_top__DOT__dut__DOT__fill_data, 
                                                            (0x7fU 
                                                             & VL_SHIFTL_III(7,32,32, 
                                                                             VL_EXTEND_II(32,2, 
                                                                                ([&]() {
                                        __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__142__a 
                                            = vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__pending_addr;
                                        __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__142__Vfuncout 
                                            = (3U & (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__142__a));
                                    }(), (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__142__Vfuncout))), 5U)), 0x20U);
            }
        }
    }
    vlSelf->tb_top__DOT__dut__DOT__u_arb__DOT__last 
        = __Vdly__tb_top__DOT__dut__DOT__u_arb__DOT__last;
    if (__Vdlyvset__tb_top__DOT__dut__DOT__u_mem__DOT__mem__v0) {
        vlSelf->tb_top__DOT__dut__DOT__u_mem__DOT__mem[__Vdlyvdim0__tb_top__DOT__dut__DOT__u_mem__DOT__mem__v0] 
            = __Vdlyvval__tb_top__DOT__dut__DOT__u_mem__DOT__mem__v0;
        vlSelf->tb_top__DOT__dut__DOT__u_mem__DOT__mem[__Vdlyvdim0__tb_top__DOT__dut__DOT__u_mem__DOT__mem__v1] 
            = __Vdlyvval__tb_top__DOT__dut__DOT__u_mem__DOT__mem__v1;
        vlSelf->tb_top__DOT__dut__DOT__u_mem__DOT__mem[__Vdlyvdim0__tb_top__DOT__dut__DOT__u_mem__DOT__mem__v2] 
            = __Vdlyvval__tb_top__DOT__dut__DOT__u_mem__DOT__mem__v2;
        vlSelf->tb_top__DOT__dut__DOT__u_mem__DOT__mem[__Vdlyvdim0__tb_top__DOT__dut__DOT__u_mem__DOT__mem__v3] 
            = __Vdlyvval__tb_top__DOT__dut__DOT__u_mem__DOT__mem__v3;
    }
    vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__state 
        = __Vdly__tb_top__DOT__dut__DOT__u_cache1__DOT__state;
    vlSelf->tb_top__DOT__dut__DOT__snoop_shared_c1 
        = __Vdly__tb_top__DOT__dut__DOT__snoop_shared_c1;
    vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__pending_we 
        = __Vdly__tb_top__DOT__dut__DOT__u_cache1__DOT__pending_we;
    vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__pending_addr 
        = __Vdly__tb_top__DOT__dut__DOT__u_cache1__DOT__pending_addr;
    vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__pending_wdata 
        = __Vdly__tb_top__DOT__dut__DOT__u_cache1__DOT__pending_wdata;
    vlSelf->tb_top__DOT__dut__DOT__bus_cmd_c1 = __Vdly__tb_top__DOT__dut__DOT__bus_cmd_c1;
    if (__Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v0) {
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__tag[0U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__tag[1U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__tag[2U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__tag[3U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__tag[4U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__tag[5U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__tag[6U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__tag[7U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data[0U][0U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data[0U][1U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data[0U][2U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data[0U][3U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data[1U][0U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data[1U][1U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data[1U][2U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data[1U][3U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data[2U][0U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data[2U][1U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data[2U][2U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data[2U][3U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data[3U][0U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data[3U][1U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data[3U][2U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data[3U][3U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data[4U][0U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data[4U][1U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data[4U][2U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data[4U][3U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data[5U][0U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data[5U][1U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data[5U][2U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data[5U][3U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data[6U][0U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data[6U][1U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data[6U][2U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data[6U][3U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data[7U][0U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data[7U][1U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data[7U][2U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data[7U][3U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi[0U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi[1U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi[2U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi[3U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi[4U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi[5U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi[6U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi[7U] = 0U;
    }
    if (__Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__tag__v8) {
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__tag[__Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache1__DOT__tag__v8] 
            = __Vdlyvval__tb_top__DOT__dut__DOT__u_cache1__DOT__tag__v8;
    }
    if (__Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v8) {
        VL_ASSIGNSEL_WI(128,32,(IData)(__Vdlyvlsb__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v8), 
                        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data
                        [__Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v8], __Vdlyvval__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v8);
    }
    if (__Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v9) {
        VL_ASSIGNSEL_WI(128,32,(IData)(__Vdlyvlsb__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v9), 
                        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data
                        [__Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v9], __Vdlyvval__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v9);
    }
    if (__Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v10) {
        VL_ASSIGNSEL_WI(128,32,(IData)(__Vdlyvlsb__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v10), 
                        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data
                        [__Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v10], __Vdlyvval__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v10);
    }
    if (__Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v11) {
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data[__Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v11][0U] 
            = __Vdlyvval__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v11[0U];
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data[__Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v11][1U] 
            = __Vdlyvval__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v11[1U];
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data[__Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v11][2U] 
            = __Vdlyvval__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v11[2U];
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data[__Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v11][3U] 
            = __Vdlyvval__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v11[3U];
    }
    if (__Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v8) {
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi[__Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v8] = 1U;
    }
    if (__Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v9) {
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi[__Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v9] = 1U;
    }
    if (__Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v10) {
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi[__Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v10] = 0U;
    }
    if (__Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v11) {
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi[__Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v11] = 3U;
    }
    if (__Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v12) {
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi[__Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v12] = 0U;
    }
    if (__Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v13) {
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi[__Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v13] = 3U;
    }
    if (__Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v12) {
        VL_ASSIGNSEL_WI(128,32,(IData)(__Vdlyvlsb__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v12), 
                        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data
                        [__Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v12], __Vdlyvval__tb_top__DOT__dut__DOT__u_cache1__DOT__data__v12);
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi[__Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v14] = 3U;
    }
    if (__Vdlyvset__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v15) {
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi[__Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v15] 
            = __Vdlyvval__tb_top__DOT__dut__DOT__u_cache1__DOT__mesi__v15;
    }
    vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__state 
        = __Vdly__tb_top__DOT__dut__DOT__u_cache0__DOT__state;
    vlSelf->tb_top__DOT__dut__DOT__snoop_shared_c0 
        = __Vdly__tb_top__DOT__dut__DOT__snoop_shared_c0;
    vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__pending_we 
        = __Vdly__tb_top__DOT__dut__DOT__u_cache0__DOT__pending_we;
    vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__pending_addr 
        = __Vdly__tb_top__DOT__dut__DOT__u_cache0__DOT__pending_addr;
    vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__pending_wdata 
        = __Vdly__tb_top__DOT__dut__DOT__u_cache0__DOT__pending_wdata;
    vlSelf->tb_top__DOT__dut__DOT__bus_grant = __Vdly__tb_top__DOT__dut__DOT__bus_grant;
    vlSelf->tb_top__DOT__dut__DOT__bus_cmd_c0 = __Vdly__tb_top__DOT__dut__DOT__bus_cmd_c0;
    if (__Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v0) {
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__tag[0U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__tag[1U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__tag[2U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__tag[3U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__tag[4U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__tag[5U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__tag[6U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__tag[7U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data[0U][0U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data[0U][1U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data[0U][2U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data[0U][3U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data[1U][0U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data[1U][1U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data[1U][2U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data[1U][3U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data[2U][0U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data[2U][1U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data[2U][2U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data[2U][3U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data[3U][0U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data[3U][1U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data[3U][2U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data[3U][3U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data[4U][0U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data[4U][1U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data[4U][2U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data[4U][3U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data[5U][0U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data[5U][1U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data[5U][2U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data[5U][3U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data[6U][0U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data[6U][1U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data[6U][2U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data[6U][3U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data[7U][0U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data[7U][1U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data[7U][2U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data[7U][3U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi[0U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi[1U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi[2U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi[3U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi[4U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi[5U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi[6U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi[7U] = 0U;
    }
    if (__Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__tag__v8) {
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__tag[__Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache0__DOT__tag__v8] 
            = __Vdlyvval__tb_top__DOT__dut__DOT__u_cache0__DOT__tag__v8;
    }
    if (__Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v8) {
        VL_ASSIGNSEL_WI(128,32,(IData)(__Vdlyvlsb__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v8), 
                        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data
                        [__Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v8], __Vdlyvval__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v8);
    }
    if (__Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v9) {
        VL_ASSIGNSEL_WI(128,32,(IData)(__Vdlyvlsb__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v9), 
                        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data
                        [__Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v9], __Vdlyvval__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v9);
    }
    if (__Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v10) {
        VL_ASSIGNSEL_WI(128,32,(IData)(__Vdlyvlsb__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v10), 
                        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data
                        [__Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v10], __Vdlyvval__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v10);
    }
    if (__Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v11) {
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data[__Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v11][0U] 
            = __Vdlyvval__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v11[0U];
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data[__Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v11][1U] 
            = __Vdlyvval__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v11[1U];
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data[__Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v11][2U] 
            = __Vdlyvval__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v11[2U];
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data[__Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v11][3U] 
            = __Vdlyvval__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v11[3U];
    }
    if (__Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v8) {
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi[__Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v8] = 1U;
    }
    if (__Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v9) {
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi[__Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v9] = 1U;
    }
    if (__Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v10) {
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi[__Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v10] = 0U;
    }
    if (__Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v11) {
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi[__Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v11] = 3U;
    }
    if (__Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v12) {
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi[__Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v12] = 0U;
    }
    if (__Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v13) {
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi[__Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v13] = 3U;
    }
    if (__Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v12) {
        VL_ASSIGNSEL_WI(128,32,(IData)(__Vdlyvlsb__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v12), 
                        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data
                        [__Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v12], __Vdlyvval__tb_top__DOT__dut__DOT__u_cache0__DOT__data__v12);
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi[__Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v14] = 3U;
    }
    if (__Vdlyvset__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v15) {
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi[__Vdlyvdim0__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v15] 
            = __Vdlyvval__tb_top__DOT__dut__DOT__u_cache0__DOT__mesi__v15;
    }
    vlSelf->tb_top__DOT__dut__DOT__bus_req_w = (((IData)(vlSelf->tb_top__DOT__dut__DOT____Vcellout__u_cache1__bus_req) 
                                                 << 1U) 
                                                | (IData)(vlSelf->tb_top__DOT__dut__DOT____Vcellout__u_cache0__bus_req));
    vlSelf->tb_top__DOT__dut__DOT__snoop_dirty_any 
        = ((IData)(vlSelf->tb_top__DOT__dut__DOT__snoop_dirty_c0) 
           | (IData)(vlSelf->tb_top__DOT__dut__DOT__snoop_dirty_c1));
    if (vlSelf->tb_top__DOT__dut__DOT__bus_drive_c0) {
        vlSelf->tb_top__DOT__dut__DOT__bus_cmd_w = vlSelf->tb_top__DOT__dut__DOT__bus_cmd_c0;
        vlSelf->tb_top__DOT__dut__DOT__bus_wdata_w[0U] 
            = vlSelf->tb_top__DOT__dut__DOT__bus_data_c0[0U];
        vlSelf->tb_top__DOT__dut__DOT__bus_wdata_w[1U] 
            = vlSelf->tb_top__DOT__dut__DOT__bus_data_c0[1U];
        vlSelf->tb_top__DOT__dut__DOT__bus_wdata_w[2U] 
            = vlSelf->tb_top__DOT__dut__DOT__bus_data_c0[2U];
        vlSelf->tb_top__DOT__dut__DOT__bus_wdata_w[3U] 
            = vlSelf->tb_top__DOT__dut__DOT__bus_data_c0[3U];
        vlSelf->tb_top__DOT__dut__DOT__bus_addr_w = vlSelf->tb_top__DOT__dut__DOT__bus_addr_c0;
    } else {
        vlSelf->tb_top__DOT__dut__DOT__bus_cmd_w = vlSelf->tb_top__DOT__dut__DOT__bus_cmd_c1;
        vlSelf->tb_top__DOT__dut__DOT__bus_wdata_w[0U] 
            = vlSelf->tb_top__DOT__dut__DOT__bus_data_c1[0U];
        vlSelf->tb_top__DOT__dut__DOT__bus_wdata_w[1U] 
            = vlSelf->tb_top__DOT__dut__DOT__bus_data_c1[1U];
        vlSelf->tb_top__DOT__dut__DOT__bus_wdata_w[2U] 
            = vlSelf->tb_top__DOT__dut__DOT__bus_data_c1[2U];
        vlSelf->tb_top__DOT__dut__DOT__bus_wdata_w[3U] 
            = vlSelf->tb_top__DOT__dut__DOT__bus_data_c1[3U];
        vlSelf->tb_top__DOT__dut__DOT__bus_addr_w = vlSelf->tb_top__DOT__dut__DOT__bus_addr_c1;
    }
    vlSelf->tb_top__DOT__dut__DOT__bus_valid_w = ((IData)(vlSelf->tb_top__DOT__dut__DOT__bus_drive_c0) 
                                                  | (IData)(vlSelf->tb_top__DOT__dut__DOT__bus_drive_c1));
    if (vlSelf->tb_top__DOT__dut__DOT__snoop_dirty_any) {
        if (vlSelf->tb_top__DOT__dut__DOT__snoop_dirty_c0) {
            vlSelf->tb_top__DOT__dut__DOT__fill_data[0U] 
                = vlSelf->tb_top__DOT__dut__DOT__snoop_rdata_c0[0U];
            vlSelf->tb_top__DOT__dut__DOT__fill_data[1U] 
                = vlSelf->tb_top__DOT__dut__DOT__snoop_rdata_c0[1U];
            vlSelf->tb_top__DOT__dut__DOT__fill_data[2U] 
                = vlSelf->tb_top__DOT__dut__DOT__snoop_rdata_c0[2U];
            vlSelf->tb_top__DOT__dut__DOT__fill_data[3U] 
                = vlSelf->tb_top__DOT__dut__DOT__snoop_rdata_c0[3U];
        } else if (vlSelf->tb_top__DOT__dut__DOT__snoop_dirty_c1) {
            vlSelf->tb_top__DOT__dut__DOT__fill_data[0U] 
                = vlSelf->tb_top__DOT__dut__DOT__snoop_rdata_c1[0U];
            vlSelf->tb_top__DOT__dut__DOT__fill_data[1U] 
                = vlSelf->tb_top__DOT__dut__DOT__snoop_rdata_c1[1U];
            vlSelf->tb_top__DOT__dut__DOT__fill_data[2U] 
                = vlSelf->tb_top__DOT__dut__DOT__snoop_rdata_c1[2U];
            vlSelf->tb_top__DOT__dut__DOT__fill_data[3U] 
                = vlSelf->tb_top__DOT__dut__DOT__snoop_rdata_c1[3U];
        } else {
            vlSelf->tb_top__DOT__dut__DOT__fill_data[0U] = 0U;
            vlSelf->tb_top__DOT__dut__DOT__fill_data[1U] = 0U;
            vlSelf->tb_top__DOT__dut__DOT__fill_data[2U] = 0U;
            vlSelf->tb_top__DOT__dut__DOT__fill_data[3U] = 0U;
        }
    } else {
        vlSelf->tb_top__DOT__dut__DOT__fill_data[0U] 
            = vlSelf->tb_top__DOT__dut__DOT__mem_rdata_w[0U];
        vlSelf->tb_top__DOT__dut__DOT__fill_data[1U] 
            = vlSelf->tb_top__DOT__dut__DOT__mem_rdata_w[1U];
        vlSelf->tb_top__DOT__dut__DOT__fill_data[2U] 
            = vlSelf->tb_top__DOT__dut__DOT__mem_rdata_w[2U];
        vlSelf->tb_top__DOT__dut__DOT__fill_data[3U] 
            = vlSelf->tb_top__DOT__dut__DOT__mem_rdata_w[3U];
    }
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__112__a 
        = vlSelf->tb_top__DOT__dut__DOT__bus_addr_w;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__112__Vfuncout 
        = (7U & ((IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__112__a) 
                 >> 2U));
    vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__snoop_index 
        = __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__112__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_tag__113__a 
        = vlSelf->tb_top__DOT__dut__DOT__bus_addr_w;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_tag__113__Vfuncout 
        = (7U & ((IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_tag__113__a) 
                 >> 5U));
    vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__snoop_tag 
        = __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_tag__113__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__146__a 
        = vlSelf->tb_top__DOT__dut__DOT__bus_addr_w;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__146__Vfuncout 
        = (7U & ((IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__146__a) 
                 >> 2U));
    vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__snoop_index 
        = __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__146__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_tag__147__a 
        = vlSelf->tb_top__DOT__dut__DOT__bus_addr_w;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_tag__147__Vfuncout 
        = (7U & ((IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_tag__147__a) 
                 >> 5U));
    vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__snoop_tag 
        = __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_tag__147__Vfuncout;
    vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__snoop_hit 
        = ((IData)(vlSelf->tb_top__DOT__dut__DOT__bus_valid_w) 
           & ((~ (IData)(vlSelf->tb_top__DOT__dut__DOT__bus_drive_c0)) 
              & ((0U != vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi
                  [vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__snoop_index]) 
                 & (vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__tag
                    [vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__snoop_index] 
                    == (IData)(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__snoop_tag)))));
    vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__snoop_hit 
        = ((IData)(vlSelf->tb_top__DOT__dut__DOT__bus_valid_w) 
           & ((~ (IData)(vlSelf->tb_top__DOT__dut__DOT__bus_drive_c1)) 
              & ((0U != vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi
                  [vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__snoop_index]) 
                 & (vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__tag
                    [vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__snoop_index] 
                    == (IData)(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__snoop_tag)))));
}

VL_INLINE_OPT void Vtb_top___024root___nba_comb__TOP__0(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___nba_comb__TOP__0\n"); );
    // Init
    CData/*1:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__109__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__109__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__109__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__109__a = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__110__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__110__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__110__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__110__a = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_tag__111__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_tag__111__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_tag__111__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_tag__111__a = 0;
    CData/*1:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__143__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__143__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__143__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__143__a = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__144__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__144__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__144__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__144__a = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_tag__145__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_tag__145__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_tag__145__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_tag__145__a = 0;
    // Body
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__109__a 
        = vlSelf->tb_top__DOT__c0_addr;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__109__Vfuncout 
        = (3U & (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__109__a));
    vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__cpu_offset 
        = __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_offset__109__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__143__a 
        = vlSelf->tb_top__DOT__c1_addr;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__143__Vfuncout 
        = (3U & (IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__143__a));
    vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__cpu_offset 
        = __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_offset__143__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_tag__111__a 
        = vlSelf->tb_top__DOT__c0_addr;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_tag__111__Vfuncout 
        = (7U & ((IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_tag__111__a) 
                 >> 5U));
    vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__cpu_tag 
        = __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_tag__111__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_tag__145__a 
        = vlSelf->tb_top__DOT__c1_addr;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_tag__145__Vfuncout 
        = (7U & ((IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_tag__145__a) 
                 >> 5U));
    vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__cpu_tag 
        = __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_tag__145__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__144__a 
        = vlSelf->tb_top__DOT__c1_addr;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__144__Vfuncout 
        = (7U & ((IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__144__a) 
                 >> 2U));
    vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__cpu_index 
        = __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__144__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__110__a 
        = vlSelf->tb_top__DOT__c0_addr;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__110__Vfuncout 
        = (7U & ((IData)(__Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__110__a) 
                 >> 2U));
    vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__cpu_index 
        = __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__110__Vfuncout;
    vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__hit 
        = ((IData)(vlSelf->tb_top__DOT__c1_req) & (
                                                   (0U 
                                                    != 
                                                    vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi
                                                    [vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__cpu_index]) 
                                                   & (vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__tag
                                                      [vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__cpu_index] 
                                                      == (IData)(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__cpu_tag))));
    vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__hit 
        = ((IData)(vlSelf->tb_top__DOT__c0_req) & (
                                                   (0U 
                                                    != 
                                                    vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi
                                                    [vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__cpu_index]) 
                                                   & (vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__tag
                                                      [vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__cpu_index] 
                                                      == (IData)(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__cpu_tag))));
}

void Vtb_top___024root___eval_nba(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_top___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[4U] = 1U;
    }
    if ((3ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_top___024root___nba_comb__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[5U] = 1U;
    }
}

void Vtb_top___024root___timing_resume(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___timing_resume\n"); );
    // Body
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_he3ce3317__0.resume("@(posedge tb_top.clk)");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_he3ce33ca__0.resume("@(negedge tb_top.clk)");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VdlySched.resume();
    }
}

void Vtb_top___024root___timing_commit(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___timing_commit\n"); );
    // Body
    if ((! (1ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_he3ce3317__0.commit("@(posedge tb_top.clk)");
    }
    if ((! (2ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_he3ce33ca__0.commit("@(negedge tb_top.clk)");
    }
}

void Vtb_top___024root___eval_triggers__act(Vtb_top___024root* vlSelf);

bool Vtb_top___024root___eval_phase__act(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<3> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_top___024root___eval_triggers__act(vlSelf);
    Vtb_top___024root___timing_commit(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vtb_top___024root___timing_resume(vlSelf);
        Vtb_top___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_top___024root___eval_phase__nba(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtb_top___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_top___024root___dump_triggers__nba(Vtb_top___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_top___024root___dump_triggers__act(Vtb_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_top___024root___eval(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtb_top___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("tb/tb_mesi_system.v", 44, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vtb_top___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("tb/tb_mesi_system.v", 44, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vtb_top___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vtb_top___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtb_top___024root___eval_debug_assertions(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
