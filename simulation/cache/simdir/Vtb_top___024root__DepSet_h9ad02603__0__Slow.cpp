// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_top.h for the primary calling header

#include "Vtb_top__pch.h"
#include "Vtb_top___024root.h"

VL_ATTR_COLD void Vtb_top___024root___eval_static__TOP(Vtb_top___024root* vlSelf);

VL_ATTR_COLD void Vtb_top___024root___eval_static(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___eval_static\n"); );
    // Body
    Vtb_top___024root___eval_static__TOP(vlSelf);
    vlSelf->__Vm_traceActivity[5U] = 1U;
    vlSelf->__Vm_traceActivity[4U] = 1U;
    vlSelf->__Vm_traceActivity[3U] = 1U;
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
}

VL_ATTR_COLD void Vtb_top___024root___eval_static__TOP(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___eval_static__TOP\n"); );
    // Body
    vlSelf->tb_top__DOT__clk = 0U;
    vlSelf->tb_top__DOT__rst = 1U;
    vlSelf->tb_top__DOT__cnt_busrd = 0U;
    vlSelf->tb_top__DOT__cnt_busInv = 0U;
    vlSelf->tb_top__DOT__cnt_buswb = 0U;
}

VL_ATTR_COLD void Vtb_top___024root___eval_initial__TOP(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___eval_initial__TOP\n"); );
    // Body
    vlSelf->tb_top__DOT__dut__DOT__u_mem__DOT__k = 0U;
    while (VL_GTS_III(32, 0x100U, vlSelf->tb_top__DOT__dut__DOT__u_mem__DOT__k)) {
        vlSelf->tb_top__DOT__dut__DOT__u_mem__DOT__mem[(0xffU 
                                                        & vlSelf->tb_top__DOT__dut__DOT__u_mem__DOT__k)] 
            = vlSelf->tb_top__DOT__dut__DOT__u_mem__DOT__k;
        vlSelf->tb_top__DOT__dut__DOT__u_mem__DOT__k 
            = ((IData)(1U) + vlSelf->tb_top__DOT__dut__DOT__u_mem__DOT__k);
    }
}

VL_ATTR_COLD void Vtb_top___024root___eval_final(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_top___024root___dump_triggers__stl(Vtb_top___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_top___024root___eval_phase__stl(Vtb_top___024root* vlSelf);

VL_ATTR_COLD void Vtb_top___024root___eval_settle(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vtb_top___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("tb/tb_mesi_system.v", 44, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtb_top___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_top___024root___dump_triggers__stl(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_top___024root___stl_sequent__TOP__0(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___stl_sequent__TOP__0\n"); );
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
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__112__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__112__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__112__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_index__112__a = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_tag__113__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_tag__113__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_tag__113__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache0__DOT__f_tag__113__a = 0;
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
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__146__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__146__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__146__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_index__146__a = 0;
    CData/*2:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_tag__147__Vfuncout;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_tag__147__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_tag__147__a;
    __Vfunc_tb_top__DOT__dut__DOT__u_cache1__DOT__f_tag__147__a = 0;
    // Body
    vlSelf->tb_top__DOT__dut__DOT__bus_req_w = (((IData)(vlSelf->tb_top__DOT__dut__DOT____Vcellout__u_cache1__bus_req) 
                                                 << 1U) 
                                                | (IData)(vlSelf->tb_top__DOT__dut__DOT____Vcellout__u_cache0__bus_req));
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
    vlSelf->tb_top__DOT__dut__DOT__snoop_dirty_any 
        = ((IData)(vlSelf->tb_top__DOT__dut__DOT__snoop_dirty_c0) 
           | (IData)(vlSelf->tb_top__DOT__dut__DOT__snoop_dirty_c1));
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

VL_ATTR_COLD void Vtb_top___024root___eval_stl(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vtb_top___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[5U] = 1U;
        vlSelf->__Vm_traceActivity[4U] = 1U;
        vlSelf->__Vm_traceActivity[3U] = 1U;
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

VL_ATTR_COLD void Vtb_top___024root___eval_triggers__stl(Vtb_top___024root* vlSelf);

VL_ATTR_COLD bool Vtb_top___024root___eval_phase__stl(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtb_top___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vtb_top___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_top___024root___dump_triggers__act(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge tb_top.clk)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(negedge tb_top.clk)\n");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_top___024root___dump_triggers__nba(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge tb_top.clk)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(negedge tb_top.clk)\n");
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_top___024root___ctor_var_reset(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->tb_top__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->tb_top__DOT__rst = VL_RAND_RESET_I(1);
    vlSelf->tb_top__DOT__errors = VL_RAND_RESET_I(32);
    vlSelf->tb_top__DOT__c0_req = VL_RAND_RESET_I(1);
    vlSelf->tb_top__DOT__c1_req = VL_RAND_RESET_I(1);
    vlSelf->tb_top__DOT__c0_we = VL_RAND_RESET_I(1);
    vlSelf->tb_top__DOT__c1_we = VL_RAND_RESET_I(1);
    vlSelf->tb_top__DOT__c0_addr = VL_RAND_RESET_I(8);
    vlSelf->tb_top__DOT__c1_addr = VL_RAND_RESET_I(8);
    vlSelf->tb_top__DOT__c0_wdata = VL_RAND_RESET_I(32);
    vlSelf->tb_top__DOT__c1_wdata = VL_RAND_RESET_I(32);
    vlSelf->tb_top__DOT__c0_rdata = VL_RAND_RESET_I(32);
    vlSelf->tb_top__DOT__c1_rdata = VL_RAND_RESET_I(32);
    vlSelf->tb_top__DOT__c0_ack = VL_RAND_RESET_I(1);
    vlSelf->tb_top__DOT__c1_ack = VL_RAND_RESET_I(1);
    vlSelf->tb_top__DOT__cnt_busrd = VL_RAND_RESET_I(32);
    vlSelf->tb_top__DOT__cnt_busInv = VL_RAND_RESET_I(32);
    vlSelf->tb_top__DOT__cnt_buswb = VL_RAND_RESET_I(32);
    vlSelf->tb_top__DOT__cpu_read__Vstatic__timeout = VL_RAND_RESET_I(32);
    vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout = VL_RAND_RESET_I(32);
    vlSelf->tb_top__DOT__check_mesi__Vstatic__actual = VL_RAND_RESET_I(2);
    vlSelf->tb_top__DOT__rdata0 = VL_RAND_RESET_I(32);
    vlSelf->tb_top__DOT__rdata1 = VL_RAND_RESET_I(32);
    vlSelf->tb_top__DOT__bus_rd_before = VL_RAND_RESET_I(32);
    vlSelf->tb_top__DOT__bus_inv_before = VL_RAND_RESET_I(32);
    vlSelf->tb_top__DOT__bus_wb_before = VL_RAND_RESET_I(32);
    vlSelf->tb_top__DOT__stress__DOT__iter = VL_RAND_RESET_I(32);
    vlSelf->tb_top__DOT__stress__DOT__expected_val = VL_RAND_RESET_I(32);
    vlSelf->tb_top__DOT__dut__DOT__bus_grant = VL_RAND_RESET_I(2);
    vlSelf->tb_top__DOT__dut__DOT__bus_req_w = VL_RAND_RESET_I(2);
    vlSelf->tb_top__DOT__dut__DOT__bus_addr_c0 = VL_RAND_RESET_I(8);
    vlSelf->tb_top__DOT__dut__DOT__bus_addr_c1 = VL_RAND_RESET_I(8);
    vlSelf->tb_top__DOT__dut__DOT__bus_cmd_c0 = VL_RAND_RESET_I(2);
    vlSelf->tb_top__DOT__dut__DOT__bus_cmd_c1 = VL_RAND_RESET_I(2);
    VL_RAND_RESET_W(128, vlSelf->tb_top__DOT__dut__DOT__bus_data_c0);
    VL_RAND_RESET_W(128, vlSelf->tb_top__DOT__dut__DOT__bus_data_c1);
    vlSelf->tb_top__DOT__dut__DOT__bus_drive_c0 = VL_RAND_RESET_I(1);
    vlSelf->tb_top__DOT__dut__DOT__bus_drive_c1 = VL_RAND_RESET_I(1);
    vlSelf->tb_top__DOT__dut__DOT__bus_valid_w = VL_RAND_RESET_I(1);
    vlSelf->tb_top__DOT__dut__DOT__bus_addr_w = VL_RAND_RESET_I(8);
    vlSelf->tb_top__DOT__dut__DOT__bus_cmd_w = VL_RAND_RESET_I(2);
    VL_RAND_RESET_W(128, vlSelf->tb_top__DOT__dut__DOT__bus_wdata_w);
    VL_RAND_RESET_W(128, vlSelf->tb_top__DOT__dut__DOT__snoop_rdata_c0);
    VL_RAND_RESET_W(128, vlSelf->tb_top__DOT__dut__DOT__snoop_rdata_c1);
    vlSelf->tb_top__DOT__dut__DOT__snoop_shared_c0 = VL_RAND_RESET_I(1);
    vlSelf->tb_top__DOT__dut__DOT__snoop_shared_c1 = VL_RAND_RESET_I(1);
    vlSelf->tb_top__DOT__dut__DOT__snoop_dirty_c0 = VL_RAND_RESET_I(1);
    vlSelf->tb_top__DOT__dut__DOT__snoop_dirty_c1 = VL_RAND_RESET_I(1);
    vlSelf->tb_top__DOT__dut__DOT__snoop_dirty_any = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(128, vlSelf->tb_top__DOT__dut__DOT__mem_rdata_w);
    vlSelf->tb_top__DOT__dut__DOT__mem_valid_w = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(128, vlSelf->tb_top__DOT__dut__DOT__fill_data);
    vlSelf->tb_top__DOT__dut__DOT____Vcellout__u_cache0__bus_req = VL_RAND_RESET_I(1);
    vlSelf->tb_top__DOT__dut__DOT____Vcellout__u_cache1__bus_req = VL_RAND_RESET_I(1);
    vlSelf->tb_top__DOT__dut__DOT__u_arb__DOT__last = VL_RAND_RESET_I(1);
    vlSelf->tb_top__DOT__dut__DOT__u_arb__DOT__arb__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->tb_top__DOT__dut__DOT__u_arb__DOT__arb__DOT__j = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__tag[__Vi0] = VL_RAND_RESET_I(3);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi[__Vi0] = VL_RAND_RESET_I(2);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        VL_RAND_RESET_W(128, vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data[__Vi0]);
    }
    vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__cpu_offset = VL_RAND_RESET_I(2);
    vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__cpu_index = VL_RAND_RESET_I(3);
    vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__cpu_tag = VL_RAND_RESET_I(3);
    vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__hit = VL_RAND_RESET_I(1);
    vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__snoop_index = VL_RAND_RESET_I(3);
    vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__snoop_tag = VL_RAND_RESET_I(3);
    vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__snoop_hit = VL_RAND_RESET_I(1);
    vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__state = VL_RAND_RESET_I(3);
    vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__pending_we = VL_RAND_RESET_I(1);
    vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__pending_addr = VL_RAND_RESET_I(8);
    vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__pending_wdata = VL_RAND_RESET_I(32);
    vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__i = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__tag[__Vi0] = VL_RAND_RESET_I(3);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi[__Vi0] = VL_RAND_RESET_I(2);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        VL_RAND_RESET_W(128, vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data[__Vi0]);
    }
    vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__cpu_offset = VL_RAND_RESET_I(2);
    vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__cpu_index = VL_RAND_RESET_I(3);
    vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__cpu_tag = VL_RAND_RESET_I(3);
    vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__hit = VL_RAND_RESET_I(1);
    vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__snoop_index = VL_RAND_RESET_I(3);
    vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__snoop_tag = VL_RAND_RESET_I(3);
    vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__snoop_hit = VL_RAND_RESET_I(1);
    vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__state = VL_RAND_RESET_I(3);
    vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__pending_we = VL_RAND_RESET_I(1);
    vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__pending_addr = VL_RAND_RESET_I(8);
    vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__pending_wdata = VL_RAND_RESET_I(32);
    vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__i = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->tb_top__DOT__dut__DOT__u_mem__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->tb_top__DOT__dut__DOT__u_mem__DOT__k = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigprevexpr___TOP__tb_top__DOT__clk__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 6; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
