// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtb_top__Syms.h"


void Vtb_top___024root__trace_chg_0_sub_0(Vtb_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtb_top___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root__trace_chg_0\n"); );
    // Init
    Vtb_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_top___024root*>(voidSelf);
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtb_top___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtb_top___024root__trace_chg_0_sub_0(Vtb_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    VlWide<4>/*127:0*/ __Vtemp_3;
    // Body
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[1U] 
                     | vlSelf->__Vm_traceActivity[2U]))) {
        bufp->chgBit(oldp+0,(vlSelf->tb_top__DOT__rst));
        bufp->chgIData(oldp+1,(vlSelf->tb_top__DOT__errors),32);
        bufp->chgBit(oldp+2,(vlSelf->tb_top__DOT__c0_req));
        bufp->chgBit(oldp+3,(vlSelf->tb_top__DOT__c1_req));
        bufp->chgBit(oldp+4,(vlSelf->tb_top__DOT__c0_we));
        bufp->chgBit(oldp+5,(vlSelf->tb_top__DOT__c1_we));
        bufp->chgCData(oldp+6,(vlSelf->tb_top__DOT__c0_addr),8);
        bufp->chgCData(oldp+7,(vlSelf->tb_top__DOT__c1_addr),8);
        bufp->chgIData(oldp+8,(vlSelf->tb_top__DOT__c0_wdata),32);
        bufp->chgIData(oldp+9,(vlSelf->tb_top__DOT__c1_wdata),32);
        bufp->chgIData(oldp+10,(vlSelf->tb_top__DOT__cpu_read__Vstatic__timeout),32);
        bufp->chgIData(oldp+11,(vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout),32);
        bufp->chgCData(oldp+12,(vlSelf->tb_top__DOT__check_mesi__Vstatic__actual),2);
        bufp->chgIData(oldp+13,(vlSelf->tb_top__DOT__rdata0),32);
        bufp->chgIData(oldp+14,(vlSelf->tb_top__DOT__rdata1),32);
        bufp->chgIData(oldp+15,(vlSelf->tb_top__DOT__bus_rd_before),32);
        bufp->chgIData(oldp+16,(vlSelf->tb_top__DOT__bus_inv_before),32);
        bufp->chgIData(oldp+17,(vlSelf->tb_top__DOT__bus_wb_before),32);
        bufp->chgIData(oldp+18,(vlSelf->tb_top__DOT__stress__DOT__iter),32);
    }
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[3U] 
                     | vlSelf->__Vm_traceActivity[5U]))) {
        bufp->chgCData(oldp+19,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__cpu_offset),2);
        bufp->chgCData(oldp+20,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__cpu_index),3);
        bufp->chgCData(oldp+21,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__cpu_tag),3);
        bufp->chgCData(oldp+22,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__cpu_offset),2);
        bufp->chgCData(oldp+23,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__cpu_index),3);
        bufp->chgCData(oldp+24,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__cpu_tag),3);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[4U])) {
        bufp->chgIData(oldp+25,(vlSelf->tb_top__DOT__c0_rdata),32);
        bufp->chgIData(oldp+26,(vlSelf->tb_top__DOT__c1_rdata),32);
        bufp->chgBit(oldp+27,(vlSelf->tb_top__DOT__c0_ack));
        bufp->chgBit(oldp+28,(vlSelf->tb_top__DOT__c1_ack));
        bufp->chgBit(oldp+29,(vlSelf->tb_top__DOT__dut__DOT__bus_valid_w));
        bufp->chgCData(oldp+30,(vlSelf->tb_top__DOT__dut__DOT__bus_addr_w),8);
        bufp->chgCData(oldp+31,(vlSelf->tb_top__DOT__dut__DOT__bus_cmd_w),2);
        bufp->chgIData(oldp+32,(vlSelf->tb_top__DOT__cnt_busrd),32);
        bufp->chgIData(oldp+33,(vlSelf->tb_top__DOT__cnt_busInv),32);
        bufp->chgIData(oldp+34,(vlSelf->tb_top__DOT__cnt_buswb),32);
        bufp->chgCData(oldp+35,(vlSelf->tb_top__DOT__dut__DOT__bus_grant),2);
        bufp->chgCData(oldp+36,(vlSelf->tb_top__DOT__dut__DOT__bus_req_w),2);
        bufp->chgCData(oldp+37,(vlSelf->tb_top__DOT__dut__DOT__bus_addr_c0),8);
        bufp->chgCData(oldp+38,(vlSelf->tb_top__DOT__dut__DOT__bus_addr_c1),8);
        bufp->chgCData(oldp+39,(vlSelf->tb_top__DOT__dut__DOT__bus_cmd_c0),2);
        bufp->chgCData(oldp+40,(vlSelf->tb_top__DOT__dut__DOT__bus_cmd_c1),2);
        bufp->chgWData(oldp+41,(vlSelf->tb_top__DOT__dut__DOT__bus_data_c0),128);
        bufp->chgWData(oldp+45,(vlSelf->tb_top__DOT__dut__DOT__bus_data_c1),128);
        bufp->chgBit(oldp+49,(vlSelf->tb_top__DOT__dut__DOT__bus_drive_c0));
        bufp->chgBit(oldp+50,(vlSelf->tb_top__DOT__dut__DOT__bus_drive_c1));
        bufp->chgWData(oldp+51,(vlSelf->tb_top__DOT__dut__DOT__bus_wdata_w),128);
        bufp->chgWData(oldp+55,(vlSelf->tb_top__DOT__dut__DOT__snoop_rdata_c0),128);
        bufp->chgWData(oldp+59,(vlSelf->tb_top__DOT__dut__DOT__snoop_rdata_c1),128);
        bufp->chgBit(oldp+63,(vlSelf->tb_top__DOT__dut__DOT__snoop_shared_c0));
        bufp->chgBit(oldp+64,(vlSelf->tb_top__DOT__dut__DOT__snoop_shared_c1));
        bufp->chgBit(oldp+65,(vlSelf->tb_top__DOT__dut__DOT__snoop_dirty_c0));
        bufp->chgBit(oldp+66,(vlSelf->tb_top__DOT__dut__DOT__snoop_dirty_c1));
        bufp->chgBit(oldp+67,(((IData)(vlSelf->tb_top__DOT__dut__DOT__snoop_shared_c0) 
                               | (IData)(vlSelf->tb_top__DOT__dut__DOT__snoop_shared_c1))));
        bufp->chgBit(oldp+68,(vlSelf->tb_top__DOT__dut__DOT__snoop_dirty_any));
        if (vlSelf->tb_top__DOT__dut__DOT__snoop_dirty_c0) {
            __Vtemp_3[0U] = vlSelf->tb_top__DOT__dut__DOT__snoop_rdata_c0[0U];
            __Vtemp_3[1U] = vlSelf->tb_top__DOT__dut__DOT__snoop_rdata_c0[1U];
            __Vtemp_3[2U] = vlSelf->tb_top__DOT__dut__DOT__snoop_rdata_c0[2U];
            __Vtemp_3[3U] = vlSelf->tb_top__DOT__dut__DOT__snoop_rdata_c0[3U];
        } else if (vlSelf->tb_top__DOT__dut__DOT__snoop_dirty_c1) {
            __Vtemp_3[0U] = vlSelf->tb_top__DOT__dut__DOT__snoop_rdata_c1[0U];
            __Vtemp_3[1U] = vlSelf->tb_top__DOT__dut__DOT__snoop_rdata_c1[1U];
            __Vtemp_3[2U] = vlSelf->tb_top__DOT__dut__DOT__snoop_rdata_c1[2U];
            __Vtemp_3[3U] = vlSelf->tb_top__DOT__dut__DOT__snoop_rdata_c1[3U];
        } else {
            __Vtemp_3[0U] = 0U;
            __Vtemp_3[1U] = 0U;
            __Vtemp_3[2U] = 0U;
            __Vtemp_3[3U] = 0U;
        }
        bufp->chgWData(oldp+69,(__Vtemp_3),128);
        bufp->chgWData(oldp+73,(vlSelf->tb_top__DOT__dut__DOT__mem_rdata_w),128);
        bufp->chgBit(oldp+77,(vlSelf->tb_top__DOT__dut__DOT__mem_valid_w));
        bufp->chgWData(oldp+78,(vlSelf->tb_top__DOT__dut__DOT__fill_data),128);
        bufp->chgBit(oldp+82,(vlSelf->tb_top__DOT__dut__DOT__u_arb__DOT__last));
        bufp->chgIData(oldp+83,(vlSelf->tb_top__DOT__dut__DOT__u_arb__DOT__arb__DOT__i),32);
        bufp->chgIData(oldp+84,(vlSelf->tb_top__DOT__dut__DOT__u_arb__DOT__arb__DOT__j),32);
        bufp->chgBit(oldp+85,(vlSelf->tb_top__DOT__dut__DOT____Vcellout__u_cache0__bus_req));
        bufp->chgBit(oldp+86,((1U & (IData)(vlSelf->tb_top__DOT__dut__DOT__bus_grant))));
        bufp->chgCData(oldp+87,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__tag[0]),3);
        bufp->chgCData(oldp+88,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__tag[1]),3);
        bufp->chgCData(oldp+89,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__tag[2]),3);
        bufp->chgCData(oldp+90,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__tag[3]),3);
        bufp->chgCData(oldp+91,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__tag[4]),3);
        bufp->chgCData(oldp+92,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__tag[5]),3);
        bufp->chgCData(oldp+93,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__tag[6]),3);
        bufp->chgCData(oldp+94,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__tag[7]),3);
        bufp->chgCData(oldp+95,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi[0]),2);
        bufp->chgCData(oldp+96,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi[1]),2);
        bufp->chgCData(oldp+97,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi[2]),2);
        bufp->chgCData(oldp+98,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi[3]),2);
        bufp->chgCData(oldp+99,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi[4]),2);
        bufp->chgCData(oldp+100,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi[5]),2);
        bufp->chgCData(oldp+101,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi[6]),2);
        bufp->chgCData(oldp+102,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi[7]),2);
        bufp->chgWData(oldp+103,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data[0]),128);
        bufp->chgWData(oldp+107,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data[1]),128);
        bufp->chgWData(oldp+111,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data[2]),128);
        bufp->chgWData(oldp+115,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data[3]),128);
        bufp->chgWData(oldp+119,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data[4]),128);
        bufp->chgWData(oldp+123,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data[5]),128);
        bufp->chgWData(oldp+127,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data[6]),128);
        bufp->chgWData(oldp+131,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data[7]),128);
        bufp->chgCData(oldp+135,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__snoop_index),3);
        bufp->chgCData(oldp+136,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__snoop_tag),3);
        bufp->chgBit(oldp+137,(((IData)(vlSelf->tb_top__DOT__dut__DOT__bus_valid_w) 
                                & ((~ (IData)(vlSelf->tb_top__DOT__dut__DOT__bus_drive_c0)) 
                                   & ((0U != vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi
                                       [vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__snoop_index]) 
                                      & (vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__tag
                                         [vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__snoop_index] 
                                         == (IData)(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__snoop_tag)))))));
        bufp->chgCData(oldp+138,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__state),3);
        bufp->chgBit(oldp+139,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__pending_we));
        bufp->chgCData(oldp+140,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__pending_addr),8);
        bufp->chgIData(oldp+141,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__pending_wdata),32);
        bufp->chgIData(oldp+142,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__i),32);
        bufp->chgBit(oldp+143,(vlSelf->tb_top__DOT__dut__DOT____Vcellout__u_cache1__bus_req));
        bufp->chgBit(oldp+144,((1U & ((IData)(vlSelf->tb_top__DOT__dut__DOT__bus_grant) 
                                      >> 1U))));
        bufp->chgCData(oldp+145,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__tag[0]),3);
        bufp->chgCData(oldp+146,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__tag[1]),3);
        bufp->chgCData(oldp+147,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__tag[2]),3);
        bufp->chgCData(oldp+148,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__tag[3]),3);
        bufp->chgCData(oldp+149,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__tag[4]),3);
        bufp->chgCData(oldp+150,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__tag[5]),3);
        bufp->chgCData(oldp+151,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__tag[6]),3);
        bufp->chgCData(oldp+152,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__tag[7]),3);
        bufp->chgCData(oldp+153,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi[0]),2);
        bufp->chgCData(oldp+154,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi[1]),2);
        bufp->chgCData(oldp+155,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi[2]),2);
        bufp->chgCData(oldp+156,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi[3]),2);
        bufp->chgCData(oldp+157,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi[4]),2);
        bufp->chgCData(oldp+158,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi[5]),2);
        bufp->chgCData(oldp+159,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi[6]),2);
        bufp->chgCData(oldp+160,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi[7]),2);
        bufp->chgWData(oldp+161,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data[0]),128);
        bufp->chgWData(oldp+165,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data[1]),128);
        bufp->chgWData(oldp+169,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data[2]),128);
        bufp->chgWData(oldp+173,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data[3]),128);
        bufp->chgWData(oldp+177,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data[4]),128);
        bufp->chgWData(oldp+181,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data[5]),128);
        bufp->chgWData(oldp+185,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data[6]),128);
        bufp->chgWData(oldp+189,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data[7]),128);
        bufp->chgCData(oldp+193,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__snoop_index),3);
        bufp->chgCData(oldp+194,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__snoop_tag),3);
        bufp->chgBit(oldp+195,(((IData)(vlSelf->tb_top__DOT__dut__DOT__bus_valid_w) 
                                & ((~ (IData)(vlSelf->tb_top__DOT__dut__DOT__bus_drive_c1)) 
                                   & ((0U != vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi
                                       [vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__snoop_index]) 
                                      & (vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__tag
                                         [vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__snoop_index] 
                                         == (IData)(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__snoop_tag)))))));
        bufp->chgCData(oldp+196,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__state),3);
        bufp->chgBit(oldp+197,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__pending_we));
        bufp->chgCData(oldp+198,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__pending_addr),8);
        bufp->chgIData(oldp+199,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__pending_wdata),32);
        bufp->chgIData(oldp+200,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__i),32);
        bufp->chgCData(oldp+201,((0xfcU & VL_SHIFTR_III(8,8,32, (IData)(vlSelf->tb_top__DOT__dut__DOT__bus_addr_w), 2U))),8);
    }
    bufp->chgBit(oldp+202,(vlSelf->tb_top__DOT__clk));
    bufp->chgBit(oldp+203,(((IData)(vlSelf->tb_top__DOT__c0_req) 
                            & ((0U != vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi
                                [vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__cpu_index]) 
                               & (vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__tag
                                  [vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__cpu_index] 
                                  == (IData)(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__cpu_tag))))));
    bufp->chgBit(oldp+204,(((IData)(vlSelf->tb_top__DOT__c1_req) 
                            & ((0U != vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi
                                [vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__cpu_index]) 
                               & (vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__tag
                                  [vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__cpu_index] 
                                  == (IData)(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__cpu_tag))))));
    bufp->chgIData(oldp+205,(vlSelf->tb_top__DOT__dut__DOT__u_mem__DOT__k),32);
}

void Vtb_top___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root__trace_cleanup\n"); );
    // Init
    Vtb_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_top___024root*>(voidSelf);
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[5U] = 0U;
}
