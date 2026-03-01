// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_top.h for the primary calling header

#ifndef VERILATED_VTB_TOP___024ROOT_H_
#define VERILATED_VTB_TOP___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_top__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_top___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ tb_top__DOT__clk;
        CData/*0:0*/ tb_top__DOT__rst;
        CData/*0:0*/ tb_top__DOT__c0_req;
        CData/*0:0*/ tb_top__DOT__c1_req;
        CData/*0:0*/ tb_top__DOT__c0_we;
        CData/*0:0*/ tb_top__DOT__c1_we;
        CData/*7:0*/ tb_top__DOT__c0_addr;
        CData/*7:0*/ tb_top__DOT__c1_addr;
        CData/*0:0*/ tb_top__DOT__c0_ack;
        CData/*0:0*/ tb_top__DOT__c1_ack;
        CData/*1:0*/ tb_top__DOT__check_mesi__Vstatic__actual;
        CData/*1:0*/ tb_top__DOT__dut__DOT__bus_grant;
        CData/*1:0*/ tb_top__DOT__dut__DOT__bus_req_w;
        CData/*7:0*/ tb_top__DOT__dut__DOT__bus_addr_c0;
        CData/*7:0*/ tb_top__DOT__dut__DOT__bus_addr_c1;
        CData/*1:0*/ tb_top__DOT__dut__DOT__bus_cmd_c0;
        CData/*1:0*/ tb_top__DOT__dut__DOT__bus_cmd_c1;
        CData/*0:0*/ tb_top__DOT__dut__DOT__bus_drive_c0;
        CData/*0:0*/ tb_top__DOT__dut__DOT__bus_drive_c1;
        CData/*0:0*/ tb_top__DOT__dut__DOT__bus_valid_w;
        CData/*7:0*/ tb_top__DOT__dut__DOT__bus_addr_w;
        CData/*1:0*/ tb_top__DOT__dut__DOT__bus_cmd_w;
        CData/*0:0*/ tb_top__DOT__dut__DOT__snoop_shared_c0;
        CData/*0:0*/ tb_top__DOT__dut__DOT__snoop_shared_c1;
        CData/*0:0*/ tb_top__DOT__dut__DOT__snoop_dirty_c0;
        CData/*0:0*/ tb_top__DOT__dut__DOT__snoop_dirty_c1;
        CData/*0:0*/ tb_top__DOT__dut__DOT__snoop_dirty_any;
        CData/*0:0*/ tb_top__DOT__dut__DOT__mem_valid_w;
        CData/*0:0*/ tb_top__DOT__dut__DOT____Vcellout__u_cache0__bus_req;
        CData/*0:0*/ tb_top__DOT__dut__DOT____Vcellout__u_cache1__bus_req;
        CData/*0:0*/ tb_top__DOT__dut__DOT__u_arb__DOT__last;
        CData/*1:0*/ tb_top__DOT__dut__DOT__u_cache0__DOT__cpu_offset;
        CData/*2:0*/ tb_top__DOT__dut__DOT__u_cache0__DOT__cpu_index;
        CData/*2:0*/ tb_top__DOT__dut__DOT__u_cache0__DOT__cpu_tag;
        CData/*0:0*/ tb_top__DOT__dut__DOT__u_cache0__DOT__hit;
        CData/*2:0*/ tb_top__DOT__dut__DOT__u_cache0__DOT__snoop_index;
        CData/*2:0*/ tb_top__DOT__dut__DOT__u_cache0__DOT__snoop_tag;
        CData/*0:0*/ tb_top__DOT__dut__DOT__u_cache0__DOT__snoop_hit;
        CData/*2:0*/ tb_top__DOT__dut__DOT__u_cache0__DOT__state;
        CData/*0:0*/ tb_top__DOT__dut__DOT__u_cache0__DOT__pending_we;
        CData/*7:0*/ tb_top__DOT__dut__DOT__u_cache0__DOT__pending_addr;
        CData/*1:0*/ tb_top__DOT__dut__DOT__u_cache1__DOT__cpu_offset;
        CData/*2:0*/ tb_top__DOT__dut__DOT__u_cache1__DOT__cpu_index;
        CData/*2:0*/ tb_top__DOT__dut__DOT__u_cache1__DOT__cpu_tag;
        CData/*0:0*/ tb_top__DOT__dut__DOT__u_cache1__DOT__hit;
        CData/*2:0*/ tb_top__DOT__dut__DOT__u_cache1__DOT__snoop_index;
        CData/*2:0*/ tb_top__DOT__dut__DOT__u_cache1__DOT__snoop_tag;
        CData/*0:0*/ tb_top__DOT__dut__DOT__u_cache1__DOT__snoop_hit;
        CData/*2:0*/ tb_top__DOT__dut__DOT__u_cache1__DOT__state;
        CData/*0:0*/ tb_top__DOT__dut__DOT__u_cache1__DOT__pending_we;
        CData/*7:0*/ tb_top__DOT__dut__DOT__u_cache1__DOT__pending_addr;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_top__DOT__clk__0;
        CData/*0:0*/ __VactContinue;
        IData/*31:0*/ tb_top__DOT__errors;
        IData/*31:0*/ tb_top__DOT__c0_wdata;
        IData/*31:0*/ tb_top__DOT__c1_wdata;
        IData/*31:0*/ tb_top__DOT__c0_rdata;
        IData/*31:0*/ tb_top__DOT__c1_rdata;
        IData/*31:0*/ tb_top__DOT__cnt_busrd;
        IData/*31:0*/ tb_top__DOT__cnt_busInv;
        IData/*31:0*/ tb_top__DOT__cnt_buswb;
        IData/*31:0*/ tb_top__DOT__cpu_read__Vstatic__timeout;
        IData/*31:0*/ tb_top__DOT__cpu_write__Vstatic__timeout;
    };
    struct {
        IData/*31:0*/ tb_top__DOT__rdata0;
        IData/*31:0*/ tb_top__DOT__rdata1;
        IData/*31:0*/ tb_top__DOT__bus_rd_before;
        IData/*31:0*/ tb_top__DOT__bus_inv_before;
        IData/*31:0*/ tb_top__DOT__bus_wb_before;
        IData/*31:0*/ tb_top__DOT__stress__DOT__iter;
        IData/*31:0*/ tb_top__DOT__stress__DOT__expected_val;
        VlWide<4>/*127:0*/ tb_top__DOT__dut__DOT__bus_data_c0;
        VlWide<4>/*127:0*/ tb_top__DOT__dut__DOT__bus_data_c1;
        VlWide<4>/*127:0*/ tb_top__DOT__dut__DOT__bus_wdata_w;
        VlWide<4>/*127:0*/ tb_top__DOT__dut__DOT__snoop_rdata_c0;
        VlWide<4>/*127:0*/ tb_top__DOT__dut__DOT__snoop_rdata_c1;
        VlWide<4>/*127:0*/ tb_top__DOT__dut__DOT__mem_rdata_w;
        VlWide<4>/*127:0*/ tb_top__DOT__dut__DOT__fill_data;
        IData/*31:0*/ tb_top__DOT__dut__DOT__u_arb__DOT__arb__DOT__i;
        IData/*31:0*/ tb_top__DOT__dut__DOT__u_arb__DOT__arb__DOT__j;
        IData/*31:0*/ tb_top__DOT__dut__DOT__u_cache0__DOT__pending_wdata;
        IData/*31:0*/ tb_top__DOT__dut__DOT__u_cache0__DOT__i;
        IData/*31:0*/ tb_top__DOT__dut__DOT__u_cache1__DOT__pending_wdata;
        IData/*31:0*/ tb_top__DOT__dut__DOT__u_cache1__DOT__i;
        IData/*31:0*/ tb_top__DOT__dut__DOT__u_mem__DOT__k;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<CData/*2:0*/, 8> tb_top__DOT__dut__DOT__u_cache0__DOT__tag;
        VlUnpacked<CData/*1:0*/, 8> tb_top__DOT__dut__DOT__u_cache0__DOT__mesi;
        VlUnpacked<VlWide<4>/*127:0*/, 8> tb_top__DOT__dut__DOT__u_cache0__DOT__data;
        VlUnpacked<CData/*2:0*/, 8> tb_top__DOT__dut__DOT__u_cache1__DOT__tag;
        VlUnpacked<CData/*1:0*/, 8> tb_top__DOT__dut__DOT__u_cache1__DOT__mesi;
        VlUnpacked<VlWide<4>/*127:0*/, 8> tb_top__DOT__dut__DOT__u_cache1__DOT__data;
        VlUnpacked<IData/*31:0*/, 256> tb_top__DOT__dut__DOT__u_mem__DOT__mem;
        VlUnpacked<CData/*0:0*/, 6> __Vm_traceActivity;
    };
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_he3ce3317__0;
    VlTriggerScheduler __VtrigSched_he3ce33ca__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<3> __VactTriggered;
    VlTriggerVec<3> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtb_top__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_top___024root(Vtb_top__Syms* symsp, const char* v__name);
    ~Vtb_top___024root();
    VL_UNCOPYABLE(Vtb_top___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
