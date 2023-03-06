
int64_t __gmon_start__ = 0;

void _init() {
    int64_t rax1;

    rax1 = __gmon_start__;
    if (rax1) {
        rax1();
    }
    return;
}

int64_t deregister_tm_clones() {
    int64_t rax1;

    *reinterpret_cast<int32_t*>(&rax1) = 0x405090;
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rax1) + 4) = 0;
    if (1 || (*reinterpret_cast<int32_t*>(&rax1) = 0, *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rax1) + 4) = 0, 1)) {
        return rax1;
    } else {
        goto 0;
    }
}

struct s1 {
    void* f0;
    signed char[40] pad48;
    struct s0* f30;
    struct s0* f38;
    struct s0* f40;
    struct s0* f48;
    signed char[20] pad100;
    int32_t f64;
};

struct s0 {
    void* f0;
    struct s1* f8;
    struct s1* f10;
    int32_t f18;
    signed char[4] pad32;
    struct s0* f20;
    struct s0* f28;
    uint64_t f30;
    int64_t f38;
};

void refresh_neighbour_lists(void** rdi, void** rsi);

void** suspend_impl(void** rdi, void** rsi, int64_t rdx) {
    struct s0* r8_4;
    struct s0* rax5;
    void** r14_6;
    struct s0* rdx7;
    void** rcx8;
    struct s1* rbx9;

    if (!rdx) {
        r8_4 = *reinterpret_cast<struct s0**>(rdi + 0x90);
        rax5 = reinterpret_cast<struct s0*>((reinterpret_cast<uint64_t>(*reinterpret_cast<void**>(rdi + 0x6a)) - reinterpret_cast<uint32_t>(*reinterpret_cast<void***>(rdi + 0x6e)) << 6) + reinterpret_cast<uint64_t>(*reinterpret_cast<struct s0**>(rdi + 0x8e)));
        *reinterpret_cast<int32_t*>(&r14_6) = 0;
        *reinterpret_cast<int32_t*>(&r14_6 + 1) = 0;
        if (reinterpret_cast<uint64_t>(rax5) >= reinterpret_cast<uint64_t>(r8_4)) {
            addr_402184_3:
            return r14_6;
        } else {
            rdx7 = rax5;
            do {
                rcx8 = reinterpret_cast<void**>(0xfffffffffffffffe);
                if (!rax5->f18) {
                    rbx9 = rax5->f8;
                    if (rax5 != rbx9->f30) {
                        rbx9 = rax5->f10;
                    }
                    rbx9->f30 = rdx7;
                    if (reinterpret_cast<int32_t>(0xfffffffffffffffe) <= reinterpret_cast<int32_t>(rsi)) 
                        goto addr_402127_9;
                } else {
                    if (rax5->f18 == 1) {
                        rcx8 = reinterpret_cast<void**>(reinterpret_cast<int64_t>(rax5->f0) - reinterpret_cast<uint64_t>(rax5->f8->f0) + reinterpret_cast<uint64_t>(rax5->f10->f0));
                    }
                    if (reinterpret_cast<int32_t>(rcx8) <= reinterpret_cast<int32_t>(rsi)) 
                        goto addr_402127_9;
                }
                r14_6 = reinterpret_cast<void**>(reinterpret_cast<uint32_t>(r14_6) + 1);
                continue;
                addr_402127_9:
                __asm__("movups xmm0, [rax]");
                __asm__("movups xmm1, [rax+0x10]");
                __asm__("movups xmm2, [rax+0x20]");
                __asm__("movups xmm3, [rax+0x30]");
                __asm__("movups [rdx+0x30], xmm3");
                __asm__("movups [rdx+0x20], xmm2");
                __asm__("movups [rdx+0x10], xmm1");
                __asm__("movups [rdx], xmm0");
                ++rdx7;
                ++rax5;
            } while (reinterpret_cast<uint64_t>(rax5) < reinterpret_cast<uint64_t>(r8_4));
            if (r14_6) 
                goto addr_402157_16;
        }
    } else {
        r14_6 = *reinterpret_cast<void***>(rdi + 0x6e);
        if (r14_6) {
            addr_402157_16:
            *reinterpret_cast<void**>(rdi + 0x6a) = reinterpret_cast<void*>(reinterpret_cast<uint64_t>(*reinterpret_cast<void**>(rdi + 0x6a)) - reinterpret_cast<uint32_t>(r14_6));
            *reinterpret_cast<void***>(rdi + 0x6e) = reinterpret_cast<void**>(reinterpret_cast<uint32_t>(*reinterpret_cast<void***>(rdi + 0x6e)) - reinterpret_cast<uint32_t>(r14_6));
            *reinterpret_cast<struct s0**>(rdi + 0x90) = reinterpret_cast<struct s0*>(reinterpret_cast<uint64_t>(*reinterpret_cast<struct s0**>(rdi + 0x90)) - (reinterpret_cast<uint32_t>(r14_6) << 6));
            *reinterpret_cast<void***>(rdi + 0x70) = reinterpret_cast<void**>(reinterpret_cast<uint32_t>(*reinterpret_cast<void***>(rdi + 0x70)) + reinterpret_cast<uint32_t>(r14_6));
            refresh_neighbour_lists(rdi, rsi);
            goto addr_402184_3;
        }
    }
    *reinterpret_cast<int32_t*>(&r14_6) = 0;
    *reinterpret_cast<int32_t*>(&r14_6 + 1) = 0;
    goto addr_402184_3;
}

int64_t printf = 0x400846;

void fun_400840(int64_t rdi, void** rsi, ...) {
    goto printf;
}

int64_t puts = 0x400856;

void fun_400850(int64_t rdi, void** rsi, ...) {
    goto puts;
}

int64_t exit = 0x400866;

void fun_400860(int64_t rdi, void** rsi) {
    goto exit;
}

int64_t putchar = 0x400876;

void fun_400870(int64_t rdi) {
    goto putchar;
}

int64_t memset = 0x400886;

void fun_400880(int64_t rdi) {
    goto memset;
}

int64_t strcpy = 0x400896;

void fun_400890(int64_t rdi, void** rsi, void* rdx) {
    goto strcpy;
}

struct s4 {
    void* f0;
    signed char[48] pad56;
    void*** f38;
    struct s3* f40;
    signed char[8] pad80;
    int64_t f50;
    signed char[8] pad96;
    int32_t f60;
    int32_t f64;
};

struct s3 {
    void* f0;
    void** f8;
    struct s4* f10;
    signed char[8] pad32;
    int64_t f20;
    struct s3* f28;
    signed char[8] pad56;
    void* f38;
    int64_t f40;
    void** f48;
    void** f50;
    signed char[8] pad96;
    int64_t f60;
    void* f68;
    signed char[8] pad120;
    int64_t f78;
    void** f80;
    signed char[4] pad136;
    struct s4* f88;
    void** f90;
    signed char[8] pad160;
    void*** fa0;
    int64_t fa8;
    signed char[8] pad184;
    void** fb8;
    signed char[188] pad376;
    void* f178;
};

struct s2 {
    signed char[200] pad200;
    signed char fc8;
    signed char[199] pad400;
    void* f190;
    void* f198;
    void* f1a0;
    void* f1a8;
    void* f1b0;
    signed char[8] pad448;
    void* f1c0;
    int64_t f1c8;
    signed char[64] pad528;
    void* f210;
    signed char[16] pad552;
    struct s3* f228;
    uint64_t f230;
    struct s3* f238;
    struct s3* f240;
    struct s3* f248;
    void** f250;
};

int64_t fun_4008c0();

void fun_4008d0(void* rdi, int64_t rsi, int64_t rdx);

int32_t fun_4008e0(void* rdi, void** rsi, void* rdx, void* rcx, void* r8);

struct s3* fun_4008f0(void* rdi, void** rsi);

int64_t getfree(struct s2* rdi, void** rsi, void* rdx);

void fun_400900(int64_t rdi, void** rsi);

int64_t read_min(struct s2* rdi, void** rsi, void* rdx) {
    int64_t rax4;
    void** rsp5;
    int64_t r15_6;
    void* r14_7;
    void* rsp8;
    void* r8_9;
    int32_t eax10;
    int64_t v11;
    void* v12;
    void* v13;
    void* r12_14;
    void* r15_15;
    int1_t less16;
    void* rbx17;
    int64_t rcx18;
    struct s3* rax19;
    struct s3* r13_20;
    struct s3* rax21;
    void** rsi22;
    struct s3* rax23;
    struct s3* rbx24;
    void* r8_25;
    struct s2* v26;
    void* r15_27;
    struct s4* r14_28;
    int32_t r12d29;
    void* rbp30;
    void* rsp31;
    int32_t eax32;
    void* rdx33;
    void* v34;
    void* rcx35;
    void* v36;
    void* rax37;
    void* rcx38;
    void** rdx39;
    void* rsi40;
    void* rdi41;
    void** rdi42;
    int64_t* rdx43;
    void*** rcx44;
    int1_t less45;
    struct s2* r15_46;
    int64_t r12_47;
    void* r14_48;
    void* rbp49;
    void* rsp50;
    int32_t eax51;
    void* rax52;
    void* v53;
    void* rcx54;
    void* v55;
    void* v56;
    void* rbx57;
    void* rsi58;
    struct s3* rax59;
    void* rcx60;
    void* rcx61;
    int64_t rbp62;
    void** rdi63;
    int64_t rdx64;
    int64_t rsi65;
    void* rsi66;

    rax4 = fun_4008c0();
    rsp5 = reinterpret_cast<void**>(reinterpret_cast<int64_t>(__zero_stack_offset()) - 8 - 8 - 8 - 8 - 8 - 8 - 0x108 - 8 + 8);
    r15_6 = -1;
    if (!rax4 || (r14_7 = reinterpret_cast<void*>(rsp5 + 6), fun_4008d0(r14_7, 0xc8, rax4), rsp8 = reinterpret_cast<void*>(rsp5 - 1 + 1), eax10 = fun_4008e0(r14_7, "%ld %ld", reinterpret_cast<int64_t>(rsp8) + 8, rsp8, r8_9), eax10 != 2)) {
        addr_40171c_2:
        return r15_6;
    } else {
        v11 = rax4;
        rdi->f198 = v12;
        rdi->f1b0 = v13;
        r12_14 = reinterpret_cast<void*>(reinterpret_cast<int64_t>(v12) + reinterpret_cast<int64_t>(v12) + 1);
        rdi->f190 = r12_14;
        r15_15 = reinterpret_cast<void*>(reinterpret_cast<int64_t>(v12) + reinterpret_cast<int64_t>(v12) * 2 + reinterpret_cast<uint64_t>(v13));
        rdi->f1a8 = r15_15;
        less16 = reinterpret_cast<int64_t>(v12) < 0x3a99;
        *reinterpret_cast<int32_t*>(&rbx17) = 0x1a10000;
        *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rbx17) + 4) = 0;
        if (less16) {
            rbx17 = r15_15;
        }
        *reinterpret_cast<int32_t*>(&rcx18) = 0x1b8faa0;
        *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rcx18) + 4) = 0;
        if (less16) {
            rcx18 = 0x2dc6c0;
        }
        rdi->f1a0 = rbx17;
        rdi->f1c8 = rcx18;
        rdi->f1c0 = reinterpret_cast<void*>(reinterpret_cast<uint64_t>(rbx17) - reinterpret_cast<uint64_t>(r15_15));
        rax19 = fun_4008f0(reinterpret_cast<int64_t>(v12) + reinterpret_cast<int64_t>(v12) + 2, 0x68);
        r13_20 = rax19;
        rdi->f228 = r13_20;
        rax21 = fun_4008f0(r12_14, 64);
        rdi->f248 = rax21;
        *reinterpret_cast<int32_t*>(&rsi22) = 64;
        *reinterpret_cast<int32_t*>(&rsi22 + 1) = 0;
        rax23 = fun_4008f0(rbx17, 64);
        rsp5 = reinterpret_cast<void**>(reinterpret_cast<int64_t>(rsp8) - 8 + 8 - 8 + 8 - 8 + 8 - 8 + 8);
        rbx24 = rax23;
        rdi->f238 = rbx24;
        if (!rbx24) 
            goto addr_401621_8;
        if (!r13_20) 
            goto addr_401621_8;
        if (rax21) 
            goto addr_401452_11;
    }
    addr_401621_8:
    fun_400850("read_min(): not enough memory", 64);
    getfree(rdi, 64, v12);
    r15_6 = -1;
    goto addr_40171c_2;
    addr_401452_11:
    rdi->f230 = reinterpret_cast<uint64_t>(r12_14) * 0x68 + reinterpret_cast<uint64_t>(r13_20) + 0x68;
    rdi->f240 = reinterpret_cast<struct s3*>((reinterpret_cast<uint64_t>(r15_15) << 6) + reinterpret_cast<uint64_t>(rbx24));
    rdi->f250 = reinterpret_cast<void**>(reinterpret_cast<uint64_t>(rax21) + (reinterpret_cast<uint64_t>(r12_14) << 6));
    r8_25 = v12;
    v26 = rdi;
    if (reinterpret_cast<uint1_t>(reinterpret_cast<int64_t>(r8_25) < 0) | reinterpret_cast<uint1_t>(r8_25 == 0)) {
        *reinterpret_cast<int32_t*>(&r15_27) = 1;
        *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&r15_27) + 4) = 0;
    } else {
        r14_28 = reinterpret_cast<struct s4*>(&r13_20->f68);
        r12d29 = -1;
        *reinterpret_cast<int32_t*>(&r15_27) = 1;
        *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&r15_27) + 4) = 0;
        do {
            rbp30 = reinterpret_cast<void*>(rsp5 + 6);
            fun_4008d0(rbp30, 0xc8, v11);
            rsp31 = reinterpret_cast<void*>(rsp5 - 1 + 1);
            eax32 = fun_4008e0(rbp30, "%ld %ld", reinterpret_cast<int64_t>(rsp31) + 8, rsp31, r8_25);
            rsp5 = reinterpret_cast<void**>(reinterpret_cast<int64_t>(rsp31) - 8 + 8);
            if (eax32 != 2) 
                goto addr_401715_15;
            rdx33 = v34;
            rcx35 = v36;
            if (reinterpret_cast<int64_t>(rdx33) > reinterpret_cast<int64_t>(rcx35)) 
                goto addr_401715_15;
            r14_28->f60 = r12d29;
            r14_28->f50 = -1;
            r8_25 = v26->f198;
            rax37 = reinterpret_cast<void*>((reinterpret_cast<int64_t>(r15_27) + reinterpret_cast<int64_t>(r8_25)) * 0x68);
            *reinterpret_cast<int32_t*>(reinterpret_cast<uint64_t>(r13_20) + reinterpret_cast<int64_t>(rax37) + 96) = *reinterpret_cast<int32_t*>(&r15_27);
            *reinterpret_cast<int64_t*>(reinterpret_cast<uint64_t>(r13_20) + reinterpret_cast<int64_t>(rax37) + 80) = 1;
            r14_28->f64 = *reinterpret_cast<int32_t*>(&rdx33);
            *reinterpret_cast<int32_t*>(reinterpret_cast<uint64_t>(r13_20) + reinterpret_cast<int64_t>(rax37) + 100) = *reinterpret_cast<int32_t*>(&rcx35);
            rcx38 = reinterpret_cast<void*>(reinterpret_cast<uint64_t>(v26->f190) * 0x68);
            rdx39 = reinterpret_cast<void**>(reinterpret_cast<uint64_t>(rcx38) + reinterpret_cast<uint64_t>(r13_20));
            rbx24->f8 = rdx39;
            rbx24->f10 = r14_28;
            rsi40 = v26->f210;
            rdi41 = reinterpret_cast<void*>(reinterpret_cast<uint64_t>(rsi40) + 15);
            rbx24->f0 = rdi41;
            rbx24->f38 = rdi41;
            rbx24->f20 = *reinterpret_cast<int64_t*>(reinterpret_cast<uint64_t>(r13_20) + reinterpret_cast<uint64_t>(rcx38) + 56);
            *reinterpret_cast<struct s3**>(reinterpret_cast<uint64_t>(r13_20) + reinterpret_cast<uint64_t>(rcx38) + 56) = rbx24;
            rdi42 = reinterpret_cast<void**>(reinterpret_cast<uint64_t>(r13_20) + reinterpret_cast<int64_t>(rax37));
            rbx24->f28 = r14_28->f40;
            r14_28->f40 = rbx24;
            rbx24->f48 = rdi42;
            rbx24->f50 = rdx39;
            rbx24->f40 = 15;
            rbx24->f78 = 15;
            rbx24->f60 = *reinterpret_cast<int64_t*>(reinterpret_cast<uint64_t>(r13_20) + reinterpret_cast<int64_t>(rax37) + 56);
            rdx43 = &rbx24->f40;
            *reinterpret_cast<int64_t**>(reinterpret_cast<uint64_t>(r13_20) + reinterpret_cast<int64_t>(rax37) + 56) = rdx43;
            rbx24->f68 = *reinterpret_cast<void**>(reinterpret_cast<uint64_t>(r13_20) + reinterpret_cast<uint64_t>(rcx38) + 64);
            *reinterpret_cast<int64_t**>(reinterpret_cast<uint64_t>(r13_20) + reinterpret_cast<uint64_t>(rcx38) + 64) = rdx43;
            rbx24->f88 = r14_28;
            rbx24->f90 = rdi42;
            rcx44 = reinterpret_cast<void***>(reinterpret_cast<uint64_t>(rbx24) + 0x80);
            if (reinterpret_cast<int64_t>(rsi40) <= reinterpret_cast<int64_t>(0x98967f)) {
                rsi40 = reinterpret_cast<void*>(0x989680);
            }
            rsi22 = reinterpret_cast<void**>(reinterpret_cast<uint64_t>(rsi40) + reinterpret_cast<uint64_t>(rsi40));
            rbx24->f80 = rsi22;
            rbx24->fb8 = rsi22;
            rbx24->fa0 = r14_28->f38;
            r14_28->f38 = rcx44;
            rbx24->fa8 = *reinterpret_cast<int64_t*>(reinterpret_cast<uint64_t>(r13_20) + reinterpret_cast<int64_t>(rax37) + 64);
            *reinterpret_cast<void****>(reinterpret_cast<uint64_t>(r13_20) + reinterpret_cast<int64_t>(rax37) + 64) = rcx44;
            rbx24 = reinterpret_cast<struct s3*>(reinterpret_cast<uint64_t>(rbx24) + 0xc0);
            ++r14_28;
            --r12d29;
            less45 = reinterpret_cast<int64_t>(r15_27) < reinterpret_cast<int64_t>(r8_25);
            r15_27 = reinterpret_cast<void*>(reinterpret_cast<int64_t>(r15_27) + 1);
        } while (less45);
    }
    if (!reinterpret_cast<int1_t>(r15_27 == reinterpret_cast<int64_t>(r8_25) + 1)) {
        addr_401715_15:
        r15_6 = -1;
        goto addr_40171c_2;
    } else {
        r15_46 = v26;
        if (reinterpret_cast<int64_t>(r15_46->f1b0) <= reinterpret_cast<int64_t>(0)) {
            r12_47 = v11;
        } else {
            r14_48 = reinterpret_cast<void*>(rsp5 + 6);
            *reinterpret_cast<int32_t*>(&rbp49) = 0;
            *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rbp49) + 4) = 0;
            r12_47 = v11;
            do {
                fun_4008d0(r14_48, 0xc8, r12_47);
                rsp50 = reinterpret_cast<void*>(rsp5 - 1 + 1);
                *reinterpret_cast<int32_t*>(&rsi22) = reinterpret_cast<int32_t>("%ld %ld %ld");
                *reinterpret_cast<int32_t*>(&rsi22 + 1) = 0;
                eax51 = fun_4008e0(r14_48, "%ld %ld %ld", reinterpret_cast<int64_t>(rsp50) + 8, rsp50, reinterpret_cast<int64_t>(rsp50) + 40);
                rsp5 = reinterpret_cast<void**>(reinterpret_cast<int64_t>(rsp50) - 8 + 8);
                if (eax51 != 3) 
                    goto addr_401715_15;
                rax52 = reinterpret_cast<void*>((reinterpret_cast<int64_t>(r15_46->f198) + reinterpret_cast<int64_t>(v53)) * 0x68);
                rbx24->f8 = reinterpret_cast<void**>(reinterpret_cast<int64_t>(rax52) + reinterpret_cast<uint64_t>(r13_20));
                rcx54 = reinterpret_cast<void*>(reinterpret_cast<uint64_t>(v55) * 0x68);
                rbx24->f10 = reinterpret_cast<struct s4*>(reinterpret_cast<uint64_t>(rcx54) + reinterpret_cast<uint64_t>(r13_20));
                rbx24->f38 = v56;
                rbx24->f0 = v56;
                rbx24->f20 = *reinterpret_cast<int64_t*>(reinterpret_cast<uint64_t>(r13_20) + reinterpret_cast<int64_t>(rax52) + 56);
                *reinterpret_cast<struct s3**>(reinterpret_cast<uint64_t>(r13_20) + reinterpret_cast<int64_t>(rax52) + 56) = rbx24;
                rbx24->f28 = *reinterpret_cast<struct s3**>(reinterpret_cast<uint64_t>(r13_20) + reinterpret_cast<uint64_t>(rcx54) + 64);
                *reinterpret_cast<struct s3**>(reinterpret_cast<uint64_t>(r13_20) + reinterpret_cast<uint64_t>(rcx54) + 64) = rbx24;
                rbp49 = reinterpret_cast<void*>(reinterpret_cast<uint64_t>(rbp49) + 1);
                rbx24 = reinterpret_cast<struct s3*>(&rbx24->f40);
            } while (reinterpret_cast<int64_t>(rbp49) < reinterpret_cast<int64_t>(r15_46->f1b0));
            goto addr_401713_27;
        }
    }
    addr_401736_28:
    if (r15_46->f240 != rbx24) {
        r15_46->f240 = rbx24;
        if (reinterpret_cast<uint64_t>(r15_46->f238) >= reinterpret_cast<uint64_t>(rbx24)) {
            *reinterpret_cast<int32_t*>(&rbx57) = 0;
            *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rbx57) + 4) = 0;
        } else {
            rbx57 = reinterpret_cast<void*>((reinterpret_cast<uint64_t>(rbx24) + ~reinterpret_cast<uint64_t>(r15_46->f238) >> 6) + 1);
        }
        r15_46->f1a8 = rbx57;
        r15_46->f1b0 = rbx57;
    }
    fun_400900(r12_47, rsi22);
    r15_46->fc8 = 0;
    rsi58 = r15_46->f198;
    if (reinterpret_cast<uint1_t>(reinterpret_cast<int64_t>(rsi58) < 0) | reinterpret_cast<uint1_t>(rsi58 == 0)) {
        addr_401818_34:
        *reinterpret_cast<int32_t*>(&r15_6) = 0;
        *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&r15_6) + 4) = 0;
        goto addr_40171c_2;
    } else {
        rax59 = r15_46->f238;
        *reinterpret_cast<int32_t*>(&rcx60) = 0x989680;
        *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rcx60) + 4) = 0;
        if (reinterpret_cast<int64_t>(r15_46->f210) > reinterpret_cast<int64_t>(0x98967f)) {
            rcx60 = r15_46->f210;
        }
        rcx61 = reinterpret_cast<void*>(-(reinterpret_cast<uint64_t>(rcx60) + reinterpret_cast<uint64_t>(rcx60)));
        *reinterpret_cast<uint32_t*>(&rbp62) = *reinterpret_cast<uint32_t*>(&rsi58) & 1;
        *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rbp62) + 4) = 0;
        if (reinterpret_cast<int1_t>(rsi58 == 1)) 
            goto addr_4017c1_38;
    }
    rdi63 = &rax59->f178;
    rdx64 = rbp62 - reinterpret_cast<int64_t>(rsi58);
    *reinterpret_cast<int32_t*>(&rsi65) = 2;
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rsi65) + 4) = 0;
    do {
        *(rdi63 - 31) = rcx61;
        *(rdi63 - 24) = rcx61;
        *(rdi63 - 7) = rcx61;
        *rdi63 = rcx61;
        rdi63 = rdi63 + 48;
        rsi65 = rsi65 + 6;
        rdx64 = rdx64 + 2;
    } while (rdx64);
    if (!rbp62) 
        goto addr_401818_34; else 
        goto addr_40180b_42;
    addr_4017c1_38:
    *reinterpret_cast<int32_t*>(&rsi65) = 2;
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rsi65) + 4) = 0;
    if (rbp62) {
        addr_40180b_42:
        rsi66 = reinterpret_cast<void*>(rsi65 << 6);
        *reinterpret_cast<void**>(reinterpret_cast<uint64_t>(rax59) + reinterpret_cast<int64_t>(rsi66)) = rcx61;
        *reinterpret_cast<void**>(reinterpret_cast<uint64_t>(rax59) + reinterpret_cast<int64_t>(rsi66) + 56) = rcx61;
        goto addr_401818_34;
    } else {
        goto addr_401818_34;
    }
    addr_401713_27:
    goto addr_401736_28;
}

void fun_4008b0();

int64_t getfree(struct s2* rdi, void** rsi, void* rdx) {
    if (rdi->f228) {
        fun_4008b0();
    }
    if (rdi->f238) {
        fun_4008b0();
    }
    if (rdi->f248) {
        fun_4008b0();
    }
    __asm__("xorps xmm0, xmm0");
    __asm__("movups [rbx+0x20], xmm0");
    __asm__("movups [rbx+0x10], xmm0");
    __asm__("movups [rbx], xmm0");
    return 0;
}

int64_t fwrite = 0x4008a6;

void fun_4008a0(int64_t rdi, int64_t rsi, int64_t rdx, int64_t rcx) {
    goto fwrite;
}

int64_t free = 0x4008b6;

void fun_4008b0() {
    goto free;
}

int64_t fgets = 0x4008d6;

void fun_4008d0(void* rdi, int64_t rsi, int64_t rdx) {
    goto fgets;
}

int64_t __isoc99_sscanf = 0x4008e6;

int32_t fun_4008e0(void* rdi, void** rsi, void* rdx, void* rcx, void* r8) {
    goto __isoc99_sscanf;
}

int64_t calloc = 0x4008f6;

struct s3* fun_4008f0(void* rdi, void** rsi) {
    goto calloc;
}

struct s0* fun_400910(struct s0* rdi);

int64_t stdout = 0;

void fun_400920(int64_t rdi, void** rsi);

struct s5 {
    signed char[24] pad24;
    struct s5* f18;
    signed char[16] pad48;
    uint64_t f30;
};

int64_t resize_prob(void** rdi) {
    void* rax2;
    struct s0* rdi3;
    struct s0* rax4;
    int64_t rdi5;
    int64_t rcx6;
    struct s0* rcx7;
    struct s5* rdx8;
    struct s5* rsi9;
    struct s5* rdi10;
    void* rax11;

    rax2 = *reinterpret_cast<void**>(rdi + 0x72);
    rdi3 = *reinterpret_cast<struct s0**>(rdi + 0x8e);
    *reinterpret_cast<void**>(rdi + 0x68) = reinterpret_cast<void*>(reinterpret_cast<uint64_t>(*reinterpret_cast<void**>(rdi + 0x68)) + reinterpret_cast<uint64_t>(rax2));
    *reinterpret_cast<void***>(rdi + 0x70) = reinterpret_cast<void**>(reinterpret_cast<uint32_t>(*reinterpret_cast<void***>(rdi + 0x70)) + reinterpret_cast<uint64_t>(rax2));
    rax4 = fun_400910(rdi3);
    if (!rax4) {
        fun_400840("network %s: not enough memory\n", rdi);
        rdi5 = stdout;
        fun_400920(rdi5, rdi);
        rcx6 = -1;
    } else {
        rcx7 = *reinterpret_cast<struct s0**>(rdi + 0x8e);
        *reinterpret_cast<struct s0**>(rdi + 0x8e) = rax4;
        rdx8 = *reinterpret_cast<struct s5**>(rdi + 0x8a);
        *reinterpret_cast<struct s0**>(rdi + 0x90) = reinterpret_cast<struct s0*>((reinterpret_cast<uint64_t>(*reinterpret_cast<void**>(rdi + 0x6a)) << 6) + reinterpret_cast<uint64_t>(rax4));
        rsi9 = *reinterpret_cast<struct s5**>(rdi + 0x8c);
        rdi10 = reinterpret_cast<struct s5*>(reinterpret_cast<uint64_t>(rdx8) + 0x68);
        if (reinterpret_cast<uint64_t>(rdi10) >= reinterpret_cast<uint64_t>(rsi9)) {
            *reinterpret_cast<int32_t*>(&rcx6) = 0;
            *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rcx6) + 4) = 0;
        } else {
            rax11 = reinterpret_cast<void*>(reinterpret_cast<uint64_t>(rax4) - reinterpret_cast<uint64_t>(rcx7));
            *reinterpret_cast<int32_t*>(&rcx6) = 0;
            *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rcx6) + 4) = 0;
            do {
                if (rdi10->f18 != rdx8) {
                    rdi10->f30 = rdi10->f30 + reinterpret_cast<uint64_t>(rax11);
                }
                rdi10 = reinterpret_cast<struct s5*>(reinterpret_cast<uint64_t>(rdi10) + 0x68);
            } while (reinterpret_cast<uint64_t>(rdi10) < reinterpret_cast<uint64_t>(rsi9));
        }
    }
    return rcx6;
}

struct s6 {
    signed char[56] pad56;
    uint64_t f38;
};

struct s7 {
    signed char[64] pad64;
    uint64_t f40;
};

void refresh_neighbour_lists(void** rdi, void** rsi) {
    struct s5* rax3;
    struct s5* rcx4;
    struct s0* rcx5;
    struct s0* r8_6;
    void* rdx7;
    struct s1* rsi8;
    struct s1* rsi9;
    struct s0* rcx10;
    struct s0* rdx11;
    uint64_t rsi12;
    struct s6* rdi13;
    struct s7* rax14;
    struct s1* rax15;
    struct s1* rax16;
    int1_t cf17;

    rax3 = *reinterpret_cast<struct s5**>(rdi + 0x8a);
    rcx4 = *reinterpret_cast<struct s5**>(rdi + 0x8c);
    if (reinterpret_cast<uint64_t>(rax3) < reinterpret_cast<uint64_t>(rcx4)) {
        __asm__("xorps xmm0, xmm0");
        do {
            __asm__("movups [rax+0x38], xmm0");
            rax3 = reinterpret_cast<struct s5*>(reinterpret_cast<uint64_t>(rax3) + 0x68);
        } while (reinterpret_cast<uint64_t>(rax3) < reinterpret_cast<uint64_t>(rcx4));
    }
    rcx5 = *reinterpret_cast<struct s0**>(rdi + 0x8e);
    r8_6 = *reinterpret_cast<struct s0**>(rdi + 0x90);
    if (reinterpret_cast<uint64_t>(rcx5) < reinterpret_cast<uint64_t>(r8_6)) {
        rdx7 = reinterpret_cast<void*>(~reinterpret_cast<uint64_t>(rcx5) + reinterpret_cast<uint64_t>(r8_6));
        if (!(*reinterpret_cast<unsigned char*>(&rdx7) & 64)) {
            rsi8 = rcx5->f8;
            rcx5->f20 = rsi8->f38;
            rsi8->f38 = rcx5;
            rsi9 = rcx5->f10;
            rcx5->f28 = rsi9->f40;
            rsi9->f40 = rcx5;
            ++rcx5;
        }
        if (reinterpret_cast<uint64_t>(rdx7) >= 64) {
            rcx10 = rcx5 + 1;
            rdx11 = rcx10;
            do {
                rsi12 = reinterpret_cast<uint64_t>(rcx10 - 1);
                rdi13 = *reinterpret_cast<struct s6**>(reinterpret_cast<uint64_t>(rcx10) - 56);
                *reinterpret_cast<uint64_t*>(reinterpret_cast<uint64_t>(rcx10) - 32) = rdi13->f38;
                rdi13->f38 = rsi12;
                rax14 = *reinterpret_cast<struct s7**>(reinterpret_cast<uint64_t>(rcx10) - 48);
                *reinterpret_cast<uint64_t*>(reinterpret_cast<uint64_t>(rcx10) - 24) = rax14->f40;
                rax14->f40 = rsi12;
                rax15 = rcx10->f8;
                rcx10->f20 = rax15->f38;
                rax15->f38 = rcx10;
                rax16 = rcx10->f10;
                rcx10->f28 = rax16->f40;
                rax16->f40 = rcx10;
                rdx11 = rdx11 + 2;
                cf17 = reinterpret_cast<uint64_t>(rcx10 + 1) < reinterpret_cast<uint64_t>(r8_6);
                rcx10 = rdx11;
            } while (cf17);
        }
    }
    return;
}

int64_t fclose = 0x400906;

void fun_400900(int64_t rdi, void** rsi) {
    goto fclose;
}

void** primal_iminus(void*** rdi, int64_t* rsi, void** rdx, void** rcx, void** r8, void** r9) {
    void** rax7;
    void** r9_8;
    void** rcx9;
    void** rcx10;

    *reinterpret_cast<int32_t*>(&rax7) = 0;
    *reinterpret_cast<int32_t*>(&rax7 + 1) = 0;
    if (rdx == rcx) {
        addr_40275a_2:
        *reinterpret_cast<void***>(r8) = rdx;
        return rax7;
    } else {
        r9_8 = rdx;
        rdx = rcx;
        while (1) {
            if (*reinterpret_cast<int64_t*>(r9_8 + 22) >= *reinterpret_cast<int64_t*>(rdx + 22)) {
                if (!*reinterpret_cast<void***>(rdx + 2)) {
                    rcx9 = *reinterpret_cast<void***>(rdx + 20);
                    if (reinterpret_cast<int32_t>(*rdi) >= reinterpret_cast<int32_t>(rcx9)) {
                        addr_402702_7:
                        *rdi = rcx9;
                        *rsi = 1;
                        rax7 = rdx;
                    }
                } else {
                    if (!*reinterpret_cast<void***>(*reinterpret_cast<void***>(rdx + 6) + 6)) 
                        goto addr_40270f_10;
                    rcx9 = reinterpret_cast<void**>(1 - reinterpret_cast<uint32_t>(*reinterpret_cast<void***>(rdx + 20)));
                    if (reinterpret_cast<int32_t>(*rdi) >= reinterpret_cast<int32_t>(rcx9)) 
                        goto addr_402702_7;
                }
                addr_40270f_10:
                rdx = *reinterpret_cast<void***>(rdx + 6);
                if (r9_8 != rdx) 
                    continue; else 
                    break;
            }
            if (!*reinterpret_cast<void***>(r9_8 + 2)) {
                if (!*reinterpret_cast<void***>(*reinterpret_cast<void***>(r9_8 + 6) + 6) || (rcx10 = reinterpret_cast<void**>(1 - reinterpret_cast<uint32_t>(*reinterpret_cast<void***>(r9_8 + 20))), reinterpret_cast<int32_t>(*rdi) <= reinterpret_cast<int32_t>(rcx10))) {
                    addr_402740_14:
                    r9_8 = *reinterpret_cast<void***>(r9_8 + 6);
                    if (r9_8 == rdx) 
                        goto addr_40274d_15;
                } else {
                    addr_402733_16:
                    *rdi = rcx10;
                    *rsi = 0;
                    rax7 = r9_8;
                    goto addr_402740_14;
                }
            } else {
                rcx10 = *reinterpret_cast<void***>(r9_8 + 20);
                if (reinterpret_cast<int32_t>(*rdi) > reinterpret_cast<int32_t>(rcx10)) 
                    goto addr_402733_16;
                goto addr_402740_14;
            }
        }
    }
    goto addr_40275a_2;
    addr_40274d_15:
    goto addr_40275a_2;
}

struct s8 {
    signed char[8] pad8;
    void** f8;
    signed char[4] pad16;
    void** f10;
    signed char[4] pad24;
    int32_t f18;
};

void** update_tree(int64_t rdi, int64_t rsi, void** rdx, void** rcx, void** r8, void** r9, void** a7, void** a8, void** a9, struct s8* a10, void* a11, void** a12) {
    struct s8* r12_13;
    void* r11_14;
    void* r11_15;
    void** r13_16;
    void** rbp17;
    void** rax18;
    void** rbx19;
    int64_t r11_20;
    void** v21;
    int64_t rbx22;
    void** r10_23;
    void** r14_24;
    void*** rbp25;
    void** rbp26;
    int64_t r15_27;
    void** rbp28;
    void** rbp29;
    struct s8* r14_30;
    int64_t r10_31;
    void** rbp32;
    void** rcx33;

    r12_13 = a10;
    if (reinterpret_cast<int64_t>(a11) < reinterpret_cast<int64_t>(0) && r12_13->f8 == r9 || !(reinterpret_cast<uint1_t>(reinterpret_cast<int64_t>(a11) < reinterpret_cast<int64_t>(0)) | reinterpret_cast<uint1_t>(a11 == 0)) && r12_13->f8 == r8) {
        r11_14 = reinterpret_cast<void*>(-reinterpret_cast<uint64_t>(a11));
        if (__intrinsic() != __intrinsic()) {
            r11_14 = a11;
        }
    } else {
        r11_15 = reinterpret_cast<void*>(-reinterpret_cast<uint64_t>(a11));
        if (__intrinsic() != __intrinsic()) {
            r11_15 = a11;
        }
        r11_14 = reinterpret_cast<void*>(-reinterpret_cast<uint64_t>(r11_15));
    }
    r13_16 = a8;
    rbp17 = a7;
    rax18 = rbp17;
    while (1) {
        rbx19 = rax18;
        *reinterpret_cast<void***>(rbx19) = reinterpret_cast<void**>(reinterpret_cast<uint32_t>(*reinterpret_cast<void***>(rbx19)) + reinterpret_cast<uint64_t>(r11_14));
        rax18 = *reinterpret_cast<void***>(rbx19 + 4);
        if (rax18) 
            continue;
        while (rbx19 != rbp17) {
            rax18 = *reinterpret_cast<void***>(rbx19 + 8);
            if (rax18) 
                goto addr_402512_13;
            rbx19 = *reinterpret_cast<void***>(rbx19 + 6);
        }
        break;
        addr_402512_13:
    }
    r11_20 = *reinterpret_cast<int64_t*>(rbp17 + 22);
    if (r8 != r13_16) {
        v21 = reinterpret_cast<void**>(-reinterpret_cast<uint32_t>(rdx));
        rbx22 = r11_20;
        r10_23 = r9;
        do {
            rax18 = r8;
            r8 = *reinterpret_cast<void***>(rax18 + 6);
            r14_24 = *reinterpret_cast<void***>(rax18 + 8);
            if (r14_24) {
                *reinterpret_cast<void***>(r14_24 + 10) = *reinterpret_cast<void***>(rax18 + 10);
            }
            rbp25 = reinterpret_cast<void***>(*reinterpret_cast<void***>(rax18 + 10) + 8);
            if (!*reinterpret_cast<void***>(rax18 + 10)) {
                rbp25 = reinterpret_cast<void***>(r8 + 4);
            }
            *rbp25 = r14_24;
            *reinterpret_cast<void***>(rax18 + 6) = r10_23;
            rbp26 = *reinterpret_cast<void***>(r10_23 + 4);
            *reinterpret_cast<void***>(rax18 + 8) = rbp26;
            if (rbp26) {
                *reinterpret_cast<void***>(rbp26 + 10) = rax18;
            }
            *reinterpret_cast<void***>(r10_23 + 4) = rax18;
            *reinterpret_cast<void***>(rax18 + 10) = reinterpret_cast<void**>(0);
            *reinterpret_cast<int32_t*>(&r15_27) = 0;
            *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&r15_27) + 4) = 0;
            *reinterpret_cast<unsigned char*>(&r15_27) = reinterpret_cast<uint1_t>(*reinterpret_cast<void***>(rax18 + 2) == 0);
            rbp28 = v21;
            if (r15_27 == rdi) {
                rbp28 = rdx;
            }
            rbp29 = reinterpret_cast<void**>(reinterpret_cast<uint32_t>(rbp28) + reinterpret_cast<uint32_t>(*reinterpret_cast<void***>(rax18 + 20)));
            r14_30 = *reinterpret_cast<struct s8**>(rax18 + 12);
            r10_31 = *reinterpret_cast<int64_t*>(rax18 + 22);
            *reinterpret_cast<void***>(rax18 + 2) = *reinterpret_cast<void***>(&rsi);
            *reinterpret_cast<void***>(rax18 + 20) = rcx;
            *reinterpret_cast<struct s8**>(rax18 + 12) = r12_13;
            *reinterpret_cast<int64_t*>(rax18 + 22) = rbx22;
            rbx22 = r11_20 - r10_31;
            rsi = r15_27;
            rcx = rbp29;
            r10_23 = rax18;
            r12_13 = r14_30;
        } while (r8 != r13_16);
    }
    if (reinterpret_cast<int32_t>(rdx) <= reinterpret_cast<int32_t>(a12)) {
        rax18 = a9;
        while (r13_16 != rax18) {
            *reinterpret_cast<int64_t*>(r13_16 + 22) = *reinterpret_cast<int64_t*>(r13_16 + 22) - r11_20;
            r13_16 = *reinterpret_cast<void***>(r13_16 + 6);
        }
        while (r9 != rax18) {
            *reinterpret_cast<int64_t*>(r9 + 22) = *reinterpret_cast<int64_t*>(r9 + 22) + r11_20;
            r9 = *reinterpret_cast<void***>(r9 + 6);
        }
    } else {
        rbp32 = a9;
        if (r13_16 != rbp32) {
            rax18 = reinterpret_cast<void**>(-reinterpret_cast<uint32_t>(rdx));
            do {
                *reinterpret_cast<int64_t*>(r13_16 + 22) = *reinterpret_cast<int64_t*>(r13_16 + 22) - r11_20;
                rcx33 = rdx;
                if (static_cast<int64_t>(reinterpret_cast<int32_t>(*reinterpret_cast<void***>(r13_16 + 2))) == rdi) {
                    rcx33 = rax18;
                }
                *reinterpret_cast<void***>(r13_16 + 20) = reinterpret_cast<void**>(reinterpret_cast<uint32_t>(*reinterpret_cast<void***>(r13_16 + 20)) + reinterpret_cast<uint32_t>(rcx33));
                r13_16 = *reinterpret_cast<void***>(r13_16 + 6);
            } while (r13_16 != rbp32);
        }
        if (r9 != rbp32) {
            rax18 = reinterpret_cast<void**>(-reinterpret_cast<uint32_t>(rdx));
            __asm__("movd xmm0, r11");
            do {
                __asm__("movdqu xmm1, [r9+0x50]");
                if (static_cast<int64_t>(reinterpret_cast<int32_t>(*reinterpret_cast<void***>(r9 + 2))) != rdi) {
                }
                __asm__("movd xmm2, rcx");
                __asm__("punpcklqdq xmm2, xmm0");
                __asm__("paddq xmm2, xmm1");
                __asm__("movdqu [r9+0x50], xmm2");
                r9 = *reinterpret_cast<void***>(r9 + 6);
            } while (r9 != rbp32);
        }
    }
    return rax18;
}

struct s10 {
    int64_t f0;
    int32_t f8;
    signed char[4] pad16;
    struct s10* f10;
    struct s10* f18;
    struct s10* f20;
    signed char[8] pad48;
    int64_t* f30;
};

struct s11 {
    signed char[48] pad48;
    uint64_t f30;
    signed char[24] pad80;
    void** f50;
    signed char[12] pad96;
    int32_t f60;
};

struct s9 {
    signed char[424] pad424;
    int64_t f1a8;
    signed char[56] pad488;
    int64_t f1e8;
    signed char[16] pad512;
    void** f200;
    signed char[36] pad552;
    struct s10* f228;
    struct s11* f230;
    void** f238;
    signed char[4] pad576;
    void** f240;
    signed char[4] pad584;
    uint64_t f248;
    uint64_t f250;
    void** f258;
    signed char[4] pad608;
    int64_t f260;
    int64_t f268;
};

int64_t refresh_potential(struct s9* rdi, void** rsi, void** rdx, void** rcx, void** r8, void** r9) {
    struct s10* r8_7;
    struct s10* rdi8;
    int64_t rax9;
    struct s10* rdx10;
    struct s10* rcx11;
    int64_t rsi12;
    struct s10* rsi13;

    r8_7 = rdi->f228;
    r8_7->f0 = 0xfffffffffa0a1f00;
    rdi8 = r8_7->f10;
    *reinterpret_cast<int32_t*>(&rax9) = 0;
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rax9) + 4) = 0;
    if (rdi8 != r8_7) {
        rdx10 = rdi8;
        while (1) {
            if (!rdi8) {
                rcx11 = rdx10->f18;
            } else {
                do {
                    rdx10 = rdi8;
                    if (rdx10->f8 != 1) {
                        rcx11 = rdx10->f18;
                        rsi12 = rcx11->f0 - *rdx10->f30;
                        ++rax9;
                    } else {
                        rcx11 = rdx10->f18;
                        rsi12 = rcx11->f0 + *rdx10->f30;
                    }
                    rdx10->f0 = rsi12;
                    rdi8 = rdx10->f10;
                } while (rdi8);
            }
            rsi13 = rdx10;
            rdi8 = rdx10;
            if (!rcx11) {
                addr_400d8d_12:
                if (rdi8 != r8_7) 
                    continue; else 
                    break;
            } else {
                do {
                    rdx10 = rsi13->f20;
                    rsi13 = rcx11;
                    rdi8 = rdx10;
                    if (rdx10) 
                        goto addr_400d8d_12;
                    rcx11 = rsi13->f18;
                } while (rcx11);
            }
            *reinterpret_cast<int32_t*>(&rdx10) = 0;
            *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rdx10) + 4) = 0;
            rdi8 = rsi13;
            goto addr_400d8d_12;
        }
    }
    return rax9;
}

void primal_update_flow(void** rdi, void** rsi, void** rdx) {
    void** rax4;
    void** rax5;

    while (rdi != rdx) {
        *reinterpret_cast<int32_t*>(&rax4) = 0;
        *reinterpret_cast<int32_t*>(&rax4 + 1) = 0;
        *reinterpret_cast<unsigned char*>(&rax4) = reinterpret_cast<uint1_t>(*reinterpret_cast<void***>(rdi + 2) == 0);
        *reinterpret_cast<void***>(rdi + 20) = rax4;
        rdi = *reinterpret_cast<void***>(rdi + 6);
    }
    while (rsi != rdx) {
        *reinterpret_cast<int32_t*>(&rax5) = 0;
        *reinterpret_cast<int32_t*>(&rax5 + 1) = 0;
        *reinterpret_cast<unsigned char*>(&rax5) = reinterpret_cast<uint1_t>(!!*reinterpret_cast<void***>(rsi + 2));
        *reinterpret_cast<void***>(rsi + 20) = rax5;
        rsi = *reinterpret_cast<void***>(rsi + 6);
    }
    return;
}

struct s12 {
    signed char[16] pad16;
    int64_t f10;
};

struct s13 {
    signed char[16] pad16;
    int64_t f10;
};

struct s14 {
    signed char[16] pad16;
    int64_t f10;
};

void sort_basket(uint64_t rdi, uint64_t rsi) {
    uint64_t r15_3;
    uint64_t rax4;
    int64_t r9_5;
    uint64_t r8_6;
    uint64_t rax7;
    uint64_t r10_8;
    uint64_t rax9;
    struct s13* rdx10;
    uint64_t rsi11;
    uint64_t rcx12;
    uint64_t rax13;
    uint64_t r12_14;
    uint64_t rsi15;
    uint64_t r12_16;

    r15_3 = rsi;
    do {
        rax4 = rdi + r15_3;
        r9_5 = (*reinterpret_cast<struct s12**>(((rax4 >> 63) + rax4 & 0x3ffffffffffffffe) * 4 + 0x4050b0))->f10;
        r8_6 = r15_3;
        rax7 = rdi;
        do {
            r10_8 = rax7 + 0xffffffffffffffff;
            do {
                rax9 = r10_8;
                rdx10 = *reinterpret_cast<struct s13**>(rax9 * 8 + 0x4050b8);
                r10_8 = rax9 + 1;
            } while (rdx10->f10 > r9_5);
            rsi11 = r8_6 + 1;
            do {
                rcx12 = rsi11;
                rsi11 = rcx12 + 0xffffffffffffffff;
            } while (r9_5 > (*reinterpret_cast<struct s14**>(rcx12 * 8 + 0x4050a8))->f10);
            if (reinterpret_cast<int64_t>(r10_8) < reinterpret_cast<int64_t>(rsi11)) {
                *reinterpret_cast<struct s14**>(rax9 * 8 + 0x4050b8) = *reinterpret_cast<struct s14**>(rcx12 * 8 + 0x4050a8);
                *reinterpret_cast<struct s13**>(rcx12 * 8 + 0x4050a8) = rdx10;
            }
            *reinterpret_cast<int32_t*>(&rax13) = 0;
            *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rax13) + 4) = 0;
            *reinterpret_cast<unsigned char*>(&rax13) = reinterpret_cast<uint1_t>(reinterpret_cast<int64_t>(r10_8) <= reinterpret_cast<int64_t>(rsi11));
            r8_6 = rsi11 - rax13;
            rax7 = rax13 + r10_8;
        } while (reinterpret_cast<int64_t>(rax7) <= reinterpret_cast<int64_t>(r8_6));
        *reinterpret_cast<int32_t*>(&r12_14) = 0;
        *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&r12_14) + 4) = 0;
        *reinterpret_cast<unsigned char*>(&r12_14) = reinterpret_cast<uint1_t>(reinterpret_cast<int64_t>(r10_8) <= reinterpret_cast<int64_t>(rsi11));
        rsi15 = rsi11 - r12_14;
        r12_16 = r12_14 + r10_8;
        if (reinterpret_cast<int64_t>(rsi15) > reinterpret_cast<int64_t>(rdi)) {
            sort_basket(rdi, rsi15);
        }
    } while (reinterpret_cast<int64_t>(r12_16) < reinterpret_cast<int64_t>(r15_3) && (rdi = r12_16, reinterpret_cast<int64_t>(r12_16) < reinterpret_cast<int64_t>(51)));
    return;
}

struct s15 {
    signed char[56] pad56;
    struct s0* f38;
};

struct s16 {
    signed char[64] pad64;
    struct s0* f40;
};

void** price_out_impl(void** rdi, void** rsi) {
    uint64_t r8_3;
    int64_t rbx4;
    struct s0** v5;
    struct s0* r10_6;
    struct s0* r11_7;
    int64_t rax8;
    int64_t rax9;
    void** rax10;
    uint64_t r14_11;
    int64_t v12;
    int64_t rbx13;
    struct s0* rsi14;
    int64_t v15;
    uint64_t v16;
    void** v17;
    struct s0* rbp18;
    struct s1* r12_19;
    int64_t r15_20;
    struct s1* rdx21;
    uint64_t r13_22;
    void** rbp23;
    void* rcx24;
    struct s0* v25;
    void** r8_26;
    void** rbp27;
    void** rsi28;
    void* rdi29;
    uint64_t rcx30;
    void* rax31;
    struct s0* v32;
    uint64_t rsi33;
    void** r9_34;
    void** rdi35;
    void** r8_36;
    void* rbp37;
    uint64_t rcx38;
    void* rdi39;
    void** rcx40;
    void* rsi41;
    void* rsi42;
    struct s0* rdx43;
    uint64_t rsi44;
    struct s1* rcx45;
    struct s1* rcx46;
    struct s1* rcx47;
    struct s1* rcx48;
    struct s0* rcx49;
    struct s15* rsi50;
    struct s16* rsi51;
    uint64_t rcx52;
    uint64_t rcx53;
    int64_t rcx54;

    r8_3 = *reinterpret_cast<uint64_t*>(rdi + 0x66);
    rbx4 = *reinterpret_cast<int64_t*>(rdi + 0x84);
    if (reinterpret_cast<int64_t>(r8_3) >= reinterpret_cast<int64_t>(0x3a99)) {
        v5 = reinterpret_cast<struct s0**>(rdi + 0x90);
        r10_6 = *reinterpret_cast<struct s0**>(rdi + 0x8e);
        r11_7 = *reinterpret_cast<struct s0**>(rdi + 0x90);
        *reinterpret_cast<int32_t*>(&rax8) = 0;
        *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rax8) + 4) = 0;
        goto addr_401b51_3;
    }
    if (reinterpret_cast<int64_t>(reinterpret_cast<uint64_t>(*reinterpret_cast<void**>(rdi + 0x72)) + reinterpret_cast<uint64_t>(*reinterpret_cast<void**>(rdi + 0x6a))) <= reinterpret_cast<int64_t>(*reinterpret_cast<void**>(rdi + 0x68)) || reinterpret_cast<int64_t>(reinterpret_cast<uint64_t>(*reinterpret_cast<void**>(rdi + 0x6a)) + (r8_3 * r8_3 >> 1)) <= reinterpret_cast<int64_t>(*reinterpret_cast<void**>(rdi + 0x68))) {
        *reinterpret_cast<int32_t*>(&rax8) = 0;
        *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rax8) + 4) = 0;
    } else {
        rax9 = resize_prob(rdi);
        rax10 = reinterpret_cast<void**>(0xffffffffffffffff);
        if (rax9) {
            addr_402072_7:
            return rax10;
        } else {
            refresh_neighbour_lists(rdi, rsi);
            r8_3 = *reinterpret_cast<uint64_t*>(rdi + 0x66);
            *reinterpret_cast<int32_t*>(&rax8) = 1;
            *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rax8) + 4) = 0;
            rdi = rdi;
            rbx4 = rbx4;
        }
    }
    r10_6 = *reinterpret_cast<struct s0**>(rdi + 0x8e);
    r11_7 = *reinterpret_cast<struct s0**>(rdi + 0x90);
    v5 = reinterpret_cast<struct s0**>(rdi + 0x90);
    if (reinterpret_cast<uint1_t>(reinterpret_cast<int64_t>(r8_3) < reinterpret_cast<int64_t>(0)) | reinterpret_cast<uint1_t>(r8_3 == 0)) {
        *reinterpret_cast<int32_t*>(&r14_11) = 0;
        *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&r14_11) + 4) = 0;
        if (reinterpret_cast<int64_t>(0) >= reinterpret_cast<int64_t>(r8_3)) 
            goto addr_401fa5_11;
    } else {
        addr_401b51_3:
        *reinterpret_cast<int32_t*>(&r14_11) = 0;
        *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&r14_11) + 4) = 0;
        goto addr_401b60_12;
    }
    addr_401b80_13:
    v12 = rax8;
    rbx13 = rbx4 - 15;
    *reinterpret_cast<int32_t*>(&rsi14) = 0;
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rsi14) + 4) = 0;
    *reinterpret_cast<int32_t*>(&rax10) = 0;
    *reinterpret_cast<int32_t*>(&rax10 + 1) = 0;
    v15 = rbx13;
    v16 = r8_3;
    v17 = rdi;
    do {
        if (*reinterpret_cast<int32_t*>(reinterpret_cast<uint64_t>(r10_6) + 88) != -1) {
            r10_6->f10->f38->f10->f48 = rsi14;
            rsi14 = r10_6 + 1;
        }
        if (r10_6->f18 != -1 && (rbp18 = rsi14->f8->f48, !!rbp18)) {
            r12_19 = r10_6->f10;
            r15_20 = rbx13 - r10_6->f38 + r12_19->f64;
            while (1) {
                rdx21 = rbp18->f8;
                if (rdx21->f64 + rbp18->f38 > r15_20) 
                    goto addr_401e55_19;
                r13_22 = 30 - reinterpret_cast<uint64_t>(rdx21->f0) + reinterpret_cast<uint64_t>(r12_19->f0);
                if (reinterpret_cast<int64_t>(r13_22) >= reinterpret_cast<int64_t>(0)) 
                    goto addr_401e55_19;
                rbp23 = *reinterpret_cast<void***>(rdi + 0x70);
                if (reinterpret_cast<int32_t>(rax10) < reinterpret_cast<int32_t>(rbp23)) {
                    rcx24 = reinterpret_cast<void*>(reinterpret_cast<uint32_t>(rax10) << 6);
                    *reinterpret_cast<struct s1**>(reinterpret_cast<uint64_t>(r11_7) + reinterpret_cast<uint64_t>(rcx24) + 8) = rdx21;
                    *reinterpret_cast<struct s1**>(reinterpret_cast<uint64_t>(r11_7) + reinterpret_cast<uint64_t>(rcx24) + 16) = r12_19;
                    *reinterpret_cast<int64_t*>(reinterpret_cast<uint64_t>(r11_7) + reinterpret_cast<uint64_t>(rcx24) + 56) = 30;
                    *reinterpret_cast<void**>(reinterpret_cast<uint64_t>(r11_7) + reinterpret_cast<uint64_t>(rcx24)) = reinterpret_cast<void*>(30);
                    *reinterpret_cast<uint64_t*>(reinterpret_cast<uint64_t>(r11_7) + reinterpret_cast<uint64_t>(rcx24) + 48) = r13_22;
                    if (!rax10) {
                        *reinterpret_cast<int32_t*>(&rax10) = 1;
                        *reinterpret_cast<int32_t*>(&rax10 + 1) = 0;
                        goto addr_401e55_19;
                    } else {
                        v25 = rsi14;
                        r8_26 = reinterpret_cast<void**>(reinterpret_cast<uint32_t>(rax10) + 1);
                        rbp27 = r8_26;
                        do {
                            rbp27 = reinterpret_cast<void**>(reinterpret_cast<int64_t>(reinterpret_cast<uint32_t>(rbp27) + reinterpret_cast<uint64_t>(reinterpret_cast<uint32_t>(rbp27) >> 63)) >> 1);
                            rsi28 = reinterpret_cast<void**>(reinterpret_cast<uint32_t>(rbp27) + 0xffffffffffffffff);
                            rdi29 = reinterpret_cast<void*>(reinterpret_cast<uint32_t>(rsi28) << 6);
                            rcx30 = *reinterpret_cast<uint64_t*>(reinterpret_cast<uint64_t>(r11_7) + reinterpret_cast<uint64_t>(rdi29) + 48);
                            if (reinterpret_cast<int64_t>(rcx30) >= reinterpret_cast<int64_t>(r13_22)) 
                                break;
                            rax31 = reinterpret_cast<void*>(reinterpret_cast<uint32_t>(rax10) << 6);
                            *reinterpret_cast<int64_t*>(reinterpret_cast<uint64_t>(r11_7) + reinterpret_cast<uint64_t>(rax31) + 16) = *reinterpret_cast<int64_t*>(reinterpret_cast<uint64_t>(r11_7) + reinterpret_cast<uint64_t>(rdi29) + 16);
                            __asm__("movups xmm0, [r11+rdi]");
                            __asm__("movups [r11+rax], xmm0");
                            *reinterpret_cast<void**>(reinterpret_cast<uint64_t>(r11_7) + reinterpret_cast<uint64_t>(rax31) + 56) = *reinterpret_cast<void**>(reinterpret_cast<uint64_t>(r11_7) + reinterpret_cast<uint64_t>(rdi29));
                            *reinterpret_cast<uint64_t*>(reinterpret_cast<uint64_t>(r11_7) + reinterpret_cast<uint64_t>(rax31) + 48) = rcx30;
                            *reinterpret_cast<struct s1**>(reinterpret_cast<uint64_t>(r11_7) + reinterpret_cast<uint64_t>(rdi29) + 8) = rdx21;
                            *reinterpret_cast<struct s1**>(reinterpret_cast<uint64_t>(r11_7) + reinterpret_cast<uint64_t>(rdi29) + 16) = r12_19;
                            *reinterpret_cast<void**>(reinterpret_cast<uint64_t>(r11_7) + reinterpret_cast<uint64_t>(rdi29)) = reinterpret_cast<void*>(30);
                            *reinterpret_cast<int64_t*>(reinterpret_cast<uint64_t>(r11_7) + reinterpret_cast<uint64_t>(rdi29) + 56) = 30;
                            *reinterpret_cast<uint64_t*>(reinterpret_cast<uint64_t>(r11_7) + reinterpret_cast<uint64_t>(rdi29) + 48) = r13_22;
                            rax10 = rsi28;
                        } while (rsi28);
                        rax10 = r8_26;
                        rdi = v17;
                        rbx13 = v15;
                        r8_3 = v16;
                        rsi14 = v25;
                        goto addr_401e55_19;
                    }
                }
                if (reinterpret_cast<int64_t>(r11_7->f30) <= reinterpret_cast<int64_t>(r13_22)) {
                    addr_401e55_19:
                    rbp18 = rdx21->f48;
                    if (rbp18) 
                        continue; else 
                        break;
                } else {
                    v32 = rsi14;
                    r11_7->f8 = rdx21;
                    r11_7->f10 = r12_19;
                    r11_7->f38 = 30;
                    r11_7->f0 = reinterpret_cast<void*>(30);
                    r11_7->f30 = r13_22;
                    *reinterpret_cast<int32_t*>(&rsi33) = 0;
                    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rsi33) + 4) = 0;
                    *reinterpret_cast<unsigned char*>(&rsi33) = reinterpret_cast<uint1_t>(*reinterpret_cast<int64_t*>(reinterpret_cast<uint64_t>(r11_7) + 0x70) > *reinterpret_cast<int64_t*>(reinterpret_cast<uint64_t>(r11_7) + 0xb0));
                    r9_34 = reinterpret_cast<void**>(3 - rsi33);
                    if (reinterpret_cast<int32_t>(r9_34) <= reinterpret_cast<int32_t>(rbp23)) {
                        *reinterpret_cast<int32_t*>(&rdi35) = 1;
                        *reinterpret_cast<int32_t*>(&rdi35 + 1) = 0;
                        rsi14 = v32;
                        do {
                            r8_36 = r9_34;
                            rbp37 = reinterpret_cast<void*>(reinterpret_cast<uint32_t>(reinterpret_cast<uint32_t>(r8_36) + 0xffffffffffffffff) << 6);
                            rcx38 = *reinterpret_cast<uint64_t*>(reinterpret_cast<uint64_t>(r11_7) + reinterpret_cast<uint64_t>(rbp37) + 48);
                            if (reinterpret_cast<int64_t>(rcx38) <= reinterpret_cast<int64_t>(r13_22)) 
                                break;
                            rdi39 = reinterpret_cast<void*>(reinterpret_cast<uint32_t>(rdi35) << 6);
                            *reinterpret_cast<int64_t*>(reinterpret_cast<uint64_t>(r11_7) + reinterpret_cast<uint64_t>(rdi39) - 48) = *reinterpret_cast<int64_t*>(reinterpret_cast<uint64_t>(r11_7) + reinterpret_cast<uint64_t>(rbp37) + 16);
                            __asm__("movups xmm0, [r11+rbp]");
                            __asm__("movups [r11+rdi-0x40], xmm0");
                            *reinterpret_cast<void**>(reinterpret_cast<uint64_t>(r11_7) + reinterpret_cast<uint64_t>(rdi39) - 8) = *reinterpret_cast<void**>(reinterpret_cast<uint64_t>(r11_7) + reinterpret_cast<uint64_t>(rbp37));
                            *reinterpret_cast<uint64_t*>(reinterpret_cast<uint64_t>(r11_7) + reinterpret_cast<uint64_t>(rdi39) - 16) = rcx38;
                            *reinterpret_cast<struct s1**>(reinterpret_cast<uint64_t>(r11_7) + reinterpret_cast<uint64_t>(rbp37) + 8) = rdx21;
                            *reinterpret_cast<struct s1**>(reinterpret_cast<uint64_t>(r11_7) + reinterpret_cast<uint64_t>(rbp37) + 16) = r12_19;
                            *reinterpret_cast<void**>(reinterpret_cast<uint64_t>(r11_7) + reinterpret_cast<uint64_t>(rbp37)) = reinterpret_cast<void*>(30);
                            *reinterpret_cast<int64_t*>(reinterpret_cast<uint64_t>(r11_7) + reinterpret_cast<uint64_t>(rbp37) + 56) = 30;
                            *reinterpret_cast<uint64_t*>(reinterpret_cast<uint64_t>(r11_7) + reinterpret_cast<uint64_t>(rbp37) + 48) = r13_22;
                            r9_34 = reinterpret_cast<void**>(reinterpret_cast<uint32_t>(r8_36) + reinterpret_cast<uint32_t>(r8_36));
                            rcx40 = reinterpret_cast<void**>(reinterpret_cast<uint32_t>(r8_36) + reinterpret_cast<uint32_t>(r8_36) + 1);
                            rbp23 = rbp23;
                            if (reinterpret_cast<int32_t>(rcx40) <= reinterpret_cast<int32_t>(rbp23)) {
                                rsi41 = reinterpret_cast<void*>(reinterpret_cast<uint32_t>(r9_34) << 6);
                                if (*reinterpret_cast<int64_t*>(reinterpret_cast<uint64_t>(r11_7) + reinterpret_cast<uint64_t>(rsi41) - 16) >= *reinterpret_cast<int64_t*>(reinterpret_cast<uint64_t>(r11_7) + reinterpret_cast<uint64_t>(rsi41) + 48)) {
                                    rcx40 = r9_34;
                                }
                                r9_34 = rcx40;
                            }
                            rsi14 = v32;
                            r12_19 = r12_19;
                            rdi35 = r8_36;
                        } while (reinterpret_cast<int32_t>(r9_34) <= reinterpret_cast<int32_t>(rbp23));
                        goto addr_401e0d_37;
                    } else {
                        rsi14 = v32;
                        goto addr_401e55_19;
                    }
                }
                rdi = v17;
                r8_3 = v16;
                r12_19 = r12_19;
                rbx13 = v15;
                goto addr_401e55_19;
                addr_401e0d_37:
                rdi = v17;
                rbx13 = v15;
                r8_3 = v16;
                goto addr_401e55_19;
            }
        }
        ++r14_11;
        r10_6 = r10_6 + 3;
    } while (r14_11 != r8_3);
    if (!rax10) {
        addr_401fa5_11:
        *reinterpret_cast<int32_t*>(&rax10) = 0;
        *reinterpret_cast<int32_t*>(&rax10 + 1) = 0;
        goto addr_402072_7;
    } else {
        rsi42 = reinterpret_cast<void*>(reinterpret_cast<uint32_t>(rax10) << 6);
        rdx43 = reinterpret_cast<struct s0*>(reinterpret_cast<uint64_t>(r11_7) + reinterpret_cast<uint64_t>(rsi42));
        *v5 = rdx43;
        rsi44 = reinterpret_cast<uint64_t>(rsi42) + 0xffffffffffffffc0;
        if (!v12) {
            if (!(*reinterpret_cast<unsigned char*>(&rsi44) & 64)) {
                r11_7->f30 = 0;
                r11_7->f18 = 1;
                rcx45 = r11_7->f8;
                r11_7->f20 = rcx45->f38;
                rcx45->f38 = r11_7;
                rcx46 = r11_7->f10;
                r11_7->f28 = rcx46->f40;
                rcx46->f40 = r11_7;
                ++r11_7;
            }
            if (rsi44) {
                do {
                    r11_7->f30 = 0;
                    r11_7->f18 = 1;
                    rcx47 = r11_7->f8;
                    r11_7->f20 = rcx47->f38;
                    rcx47->f38 = r11_7;
                    rcx48 = r11_7->f10;
                    r11_7->f28 = rcx48->f40;
                    rcx48->f40 = r11_7;
                    rcx49 = r11_7 + 1;
                    *reinterpret_cast<int64_t*>(reinterpret_cast<uint64_t>(r11_7) + 0x70) = 0;
                    *reinterpret_cast<int32_t*>(reinterpret_cast<uint64_t>(r11_7) + 88) = 1;
                    rsi50 = *reinterpret_cast<struct s15**>(reinterpret_cast<uint64_t>(r11_7) + 72);
                    *reinterpret_cast<struct s0**>(reinterpret_cast<uint64_t>(r11_7) + 96) = rsi50->f38;
                    rsi50->f38 = rcx49;
                    rsi51 = *reinterpret_cast<struct s16**>(reinterpret_cast<uint64_t>(r11_7) + 80);
                    *reinterpret_cast<struct s0**>(reinterpret_cast<uint64_t>(r11_7) + 0x68) = rsi51->f40;
                    rsi51->f40 = rcx49;
                    r11_7 = r11_7 + 2;
                } while (rdx43 != r11_7);
            }
        } else {
            *reinterpret_cast<uint32_t*>(&rcx52) = (*reinterpret_cast<uint32_t*>(&rsi44) >> 6) + 1;
            *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rcx52) + 4) = 0;
            rcx53 = rcx52 & 7;
            if (rcx53) {
                rcx54 = reinterpret_cast<int64_t>(-rcx53);
                do {
                    r11_7->f30 = 0;
                    r11_7->f18 = 1;
                    ++r11_7;
                    ++rcx54;
                } while (rcx54);
            }
            if (rsi44 >= 0x1c0) {
                do {
                    r11_7->f30 = 0;
                    r11_7->f18 = 1;
                    *reinterpret_cast<int64_t*>(reinterpret_cast<uint64_t>(r11_7) + 0x70) = 0;
                    *reinterpret_cast<int32_t*>(reinterpret_cast<uint64_t>(r11_7) + 88) = 1;
                    *reinterpret_cast<int64_t*>(reinterpret_cast<uint64_t>(r11_7) + 0xb0) = 0;
                    *reinterpret_cast<int32_t*>(reinterpret_cast<uint64_t>(r11_7) + 0x98) = 1;
                    *reinterpret_cast<int64_t*>(reinterpret_cast<uint64_t>(r11_7) + 0xf0) = 0;
                    *reinterpret_cast<int32_t*>(reinterpret_cast<uint64_t>(r11_7) + 0xd8) = 1;
                    *reinterpret_cast<int64_t*>(reinterpret_cast<uint64_t>(r11_7) + 0x130) = 0;
                    *reinterpret_cast<int32_t*>(reinterpret_cast<uint64_t>(r11_7) + 0x118) = 1;
                    *reinterpret_cast<int64_t*>(reinterpret_cast<uint64_t>(r11_7) + 0x170) = 0;
                    *reinterpret_cast<int32_t*>(reinterpret_cast<uint64_t>(r11_7) + 0x158) = 1;
                    *reinterpret_cast<int64_t*>(reinterpret_cast<uint64_t>(r11_7) + 0x1b0) = 0;
                    *reinterpret_cast<int32_t*>(reinterpret_cast<uint64_t>(r11_7) + 0x198) = 1;
                    *reinterpret_cast<int64_t*>(reinterpret_cast<uint64_t>(r11_7) + 0x1f0) = 0;
                    *reinterpret_cast<int32_t*>(reinterpret_cast<uint64_t>(r11_7) + 0x1d8) = 1;
                    r11_7 = r11_7 + 8;
                } while (rdx43 != r11_7);
            }
        }
        *reinterpret_cast<void**>(rdi + 0x6a) = reinterpret_cast<void*>(reinterpret_cast<uint64_t>(*reinterpret_cast<void**>(rdi + 0x6a)) + reinterpret_cast<uint32_t>(rax10));
        *reinterpret_cast<void***>(rdi + 0x6e) = reinterpret_cast<void**>(reinterpret_cast<uint32_t>(*reinterpret_cast<void***>(rdi + 0x6e)) + reinterpret_cast<uint32_t>(rax10));
        *reinterpret_cast<void***>(rdi + 0x70) = reinterpret_cast<void**>(reinterpret_cast<uint32_t>(*reinterpret_cast<void***>(rdi + 0x70)) - reinterpret_cast<uint32_t>(rax10));
        goto addr_402072_7;
    }
    do {
        addr_401b60_12:
        if (*reinterpret_cast<int32_t*>(reinterpret_cast<uint64_t>(r10_6) + 88) != -1) 
            break;
        ++r14_11;
        r10_6 = r10_6 + 3;
    } while (reinterpret_cast<int64_t>(r14_11) < reinterpret_cast<int64_t>(r8_3));
    if (reinterpret_cast<int64_t>(r14_11) >= reinterpret_cast<int64_t>(r8_3)) 
        goto addr_401fa5_11; else 
        goto addr_401b80_13;
}

struct s8* primal_bea_mpp(int64_t rdi, void** rsi, void** rdx, void** rcx, void** r8, void** r9);

int64_t primal_feasible(struct s9* rdi, void** rsi, void** rdx, void** rcx, void** r8, void** r9);

int64_t dual_feasible(struct s9* rdi, void** rsi, void** rdx, void** rcx, void** r8, void** r9);

int64_t primal_net_simplex(struct s9* rdi, void** rsi) {
    void* rsp3;
    struct s9* r15_4;
    int64_t rdi5;
    void** rsi6;
    void** r12_7;
    void** rcx8;
    int64_t v9;
    void** v10;
    void** rdx11;
    void** r8_12;
    void** r9_13;
    struct s8* rax14;
    void* rsp15;
    void*** rax16;
    void*** rcx17;
    int1_t less_or_equal18;
    int64_t v19;
    void*** rdx20;
    void** r14_21;
    void** rbp22;
    void** rax23;
    int32_t eax24;
    void** v25;
    int64_t rdi26;
    uint1_t zf27;
    int64_t v28;
    struct s8* r14_29;
    int32_t ebx30;
    void** rcx31;
    void* v32;
    int64_t rsi33;
    void** v34;
    void** v35;
    void** rsi36;
    void** rcx37;
    void* rax38;
    void** rdx39;
    int64_t rax40;
    int64_t rax41;

    rsp3 = reinterpret_cast<void*>(reinterpret_cast<int64_t>(__zero_stack_offset()) - 8 - 8 - 8 - 8 - 8 - 8 - 56);
    r15_4 = rdi;
    rdi5 = r15_4->f1a8;
    rsi6 = r15_4->f238;
    r12_7 = r15_4->f240;
    rcx8 = reinterpret_cast<void**>(reinterpret_cast<int64_t>(rsp3) + 8);
    v9 = rdi5;
    v10 = rsi6;
    rdx11 = r12_7;
    while (rax14 = primal_bea_mpp(rdi5, rsi6, rdx11, rcx8, r8_12, r9_13), rsp15 = reinterpret_cast<void*>(reinterpret_cast<int64_t>(rsp3) - 8 + 8), !!rax14) {
        r15_4->f258 = reinterpret_cast<void**>(reinterpret_cast<uint32_t>(r15_4->f258) + 1);
        rax16 = &rax14->f10;
        rcx17 = &rax14->f8;
        less_or_equal18 = v19 <= 0;
        rdx20 = rax16;
        if (!less_or_equal18) {
            rdx20 = rcx17;
        }
        if (!less_or_equal18) {
            rcx17 = rax16;
        }
        r14_21 = *rcx17;
        rbp22 = *rdx20;
        r8_12 = reinterpret_cast<void**>(reinterpret_cast<int64_t>(rsp15) + 24);
        rax23 = primal_iminus(reinterpret_cast<int64_t>(rsp15) + 16, reinterpret_cast<int64_t>(rsp15) + 48, r14_21, rbp22, r8_12, r9_13);
        rsp3 = reinterpret_cast<void*>(reinterpret_cast<int64_t>(rsp15) - 8 + 8);
        if (!rax23) {
            r15_4->f260 = r15_4->f260 + 1;
            eax24 = 0;
            *reinterpret_cast<unsigned char*>(&eax24) = reinterpret_cast<uint1_t>(rax14->f18 == 2);
            rax14->f18 = 2 - eax24;
            if (!0) {
                primal_update_flow(r14_21, rbp22, v25);
                rsp3 = reinterpret_cast<void*>(reinterpret_cast<int64_t>(rsp3) - 8 + 8);
            }
        } else {
            *reinterpret_cast<int32_t*>(&rdi26) = 0;
            *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rdi26) + 4) = 0;
            zf27 = reinterpret_cast<uint1_t>(v28 == 0);
            r9_13 = r14_21;
            if (zf27) {
                r9_13 = rbp22;
            }
            *reinterpret_cast<unsigned char*>(&rdi26) = zf27;
            if (zf27) {
                rbp22 = r14_21;
            }
            r14_29 = *reinterpret_cast<struct s8**>(rax23 + 12);
            ebx30 = 0;
            *reinterpret_cast<unsigned char*>(&ebx30) = reinterpret_cast<uint1_t>(v28 == static_cast<int64_t>(reinterpret_cast<int32_t>(*reinterpret_cast<void***>(rax23 + 2))));
            rcx31 = reinterpret_cast<void**>(0);
            if (reinterpret_cast<uint1_t>(reinterpret_cast<int64_t>(v32) < reinterpret_cast<int64_t>(0)) | reinterpret_cast<uint1_t>(v32 == 0)) {
                rcx31 = reinterpret_cast<void**>(1);
            }
            *reinterpret_cast<int32_t*>(&rsi33) = 0;
            *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rsi33) + 4) = 0;
            *reinterpret_cast<unsigned char*>(&rsi33) = reinterpret_cast<uint1_t>(rax14->f8 == rbp22);
            r8_12 = rbp22;
            v34 = r15_4->f200;
            v35 = *reinterpret_cast<void***>(rax23 + 6);
            update_tree(rdi26, rsi33, 1, rcx31, r8_12, r9_13, rax23, v35, 1, rax14, v32, v34);
            rsp3 = reinterpret_cast<void*>(reinterpret_cast<int64_t>(rsp3) - 8 - 8 - 8 - 8 - 8 - 8 - 8 + 8 + 48);
            rax14->f18 = 0;
            r14_29->f18 = ebx30 + 1;
            rsi36 = r15_4->f258;
            rcx37 = reinterpret_cast<void**>(reinterpret_cast<uint32_t>(rsi36) + 0xffffffffffffffff);
            rax38 = reinterpret_cast<void*>(reinterpret_cast<int64_t>(__intrinsic()) + reinterpret_cast<uint32_t>(rsi36) + 0xffffffffffffffff);
            rdx39 = reinterpret_cast<void**>(reinterpret_cast<uint64_t>(rax38) >> 63);
            if (reinterpret_cast<int1_t>(rcx37 == ((reinterpret_cast<int64_t>(rax38) >> 7) + reinterpret_cast<uint32_t>(rdx39)) * 0xc8)) {
                rax40 = refresh_potential(r15_4, rsi36, rdx39, rcx37, r8_12, r9_13);
                rsp3 = reinterpret_cast<void*>(reinterpret_cast<int64_t>(rsp3) - 8 + 8);
                r15_4->f268 = r15_4->f268 + rax40;
            }
        }
        rdi5 = v9;
        rsi6 = v10;
        rdx11 = r12_7;
        rcx8 = reinterpret_cast<void**>(reinterpret_cast<int64_t>(rsp3) + 8);
    }
    rax41 = refresh_potential(r15_4, rsi6, rdx11, rcx8, r8_12, r9_13);
    r15_4->f268 = r15_4->f268 + rax41;
    primal_feasible(r15_4, rsi6, rdx11, rcx8, r8_12, r9_13);
    dual_feasible(r15_4, rsi6, rdx11, rcx8, r8_12, r9_13);
    return 0;
}

struct s19 {
    signed char[48] pad48;
    int64_t f30;
};

struct s18 {
    signed char[48] pad48;
    struct s19* f30;
    signed char[24] pad80;
    int64_t f50;
};

struct s21 {
    signed char[96] pad96;
    int32_t f60;
};

struct s22 {
    signed char[96] pad96;
    int32_t f60;
};

struct s20 {
    signed char[8] pad8;
    struct s21* f8;
    struct s22* f10;
    int32_t f18;
    signed char[20] pad48;
    int64_t f30;
    signed char[32] pad88;
    int32_t f58;
    signed char[20] pad112;
    int64_t f70;
    signed char[32] pad152;
    int32_t f98;
    signed char[20] pad176;
    int64_t fb0;
    signed char[32] pad216;
    int32_t fd8;
    signed char[20] pad240;
    int64_t ff0;
    signed char[32] pad280;
    int32_t f118;
    signed char[20] pad304;
    int64_t f130;
    signed char[32] pad344;
    int32_t f158;
    signed char[20] pad368;
    int64_t f170;
    signed char[32] pad408;
    int32_t f198;
    signed char[20] pad432;
    int64_t f1b0;
    signed char[32] pad472;
    int32_t f1d8;
    signed char[20] pad496;
    int64_t f1f0;
};

struct s17 {
    signed char[552] pad552;
    void* f228;
    struct s18* f230;
    struct s20* f238;
    struct s20* f240;
};

void flow_cost(struct s17* rdi, void** rsi) {
    struct s20* rax3;
    struct s20* r9_4;
    uint64_t r8_5;
    uint64_t rsi6;
    struct s20* rdx7;
    uint64_t rsi8;
    int64_t rsi9;
    int64_t rcx10;
    int32_t ecx11;
    int64_t rsi12;
    int64_t rsi13;
    int64_t rcx14;
    int64_t rcx15;
    int64_t rcx16;
    int64_t rcx17;
    int64_t rcx18;
    int64_t rcx19;
    struct s18* r8_20;
    struct s18* rdx21;

    rax3 = rdi->f238;
    r9_4 = rdi->f240;
    if (rax3 != r9_4) {
        r8_5 = reinterpret_cast<uint64_t>(reinterpret_cast<int64_t>(r9_4) - 64 - reinterpret_cast<int64_t>(rax3));
        *reinterpret_cast<uint32_t*>(&rsi6) = (*reinterpret_cast<uint32_t*>(&r8_5) >> 6) + 1;
        *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rsi6) + 4) = 0;
        rdx7 = rax3;
        rsi8 = rsi6 & 7;
        if (rsi8) {
            rsi9 = reinterpret_cast<int64_t>(-rsi8);
            rdx7 = rax3;
            do {
                *reinterpret_cast<int32_t*>(&rcx10) = 0;
                *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rcx10) + 4) = 0;
                *reinterpret_cast<unsigned char*>(&rcx10) = reinterpret_cast<uint1_t>(rdx7->f18 == 2);
                rdx7->f30 = rcx10;
                rdx7 = reinterpret_cast<struct s20*>(reinterpret_cast<int64_t>(rdx7) + 64);
                ++rsi9;
            } while (rsi9);
        }
        if (r8_5 >= 0x1c0) {
            do {
                ecx11 = rdx7->f58;
                *reinterpret_cast<int32_t*>(&rsi12) = 0;
                *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rsi12) + 4) = 0;
                *reinterpret_cast<unsigned char*>(&rsi12) = reinterpret_cast<uint1_t>(rdx7->f18 == 2);
                rdx7->f30 = rsi12;
                *reinterpret_cast<int32_t*>(&rsi13) = 0;
                *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rsi13) + 4) = 0;
                *reinterpret_cast<unsigned char*>(&rsi13) = reinterpret_cast<uint1_t>(ecx11 == 2);
                rdx7->f70 = rsi13;
                *reinterpret_cast<int32_t*>(&rcx14) = 0;
                *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rcx14) + 4) = 0;
                *reinterpret_cast<unsigned char*>(&rcx14) = reinterpret_cast<uint1_t>(rdx7->f98 == 2);
                rdx7->fb0 = rcx14;
                *reinterpret_cast<int32_t*>(&rcx15) = 0;
                *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rcx15) + 4) = 0;
                *reinterpret_cast<unsigned char*>(&rcx15) = reinterpret_cast<uint1_t>(rdx7->fd8 == 2);
                rdx7->ff0 = rcx15;
                *reinterpret_cast<int32_t*>(&rcx16) = 0;
                *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rcx16) + 4) = 0;
                *reinterpret_cast<unsigned char*>(&rcx16) = reinterpret_cast<uint1_t>(rdx7->f118 == 2);
                rdx7->f130 = rcx16;
                *reinterpret_cast<int32_t*>(&rcx17) = 0;
                *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rcx17) + 4) = 0;
                *reinterpret_cast<unsigned char*>(&rcx17) = reinterpret_cast<uint1_t>(rdx7->f158 == 2);
                rdx7->f170 = rcx17;
                *reinterpret_cast<int32_t*>(&rcx18) = 0;
                *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rcx18) + 4) = 0;
                *reinterpret_cast<unsigned char*>(&rcx18) = reinterpret_cast<uint1_t>(rdx7->f198 == 2);
                rdx7->f1b0 = rcx18;
                *reinterpret_cast<int32_t*>(&rcx19) = 0;
                *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rcx19) + 4) = 0;
                *reinterpret_cast<unsigned char*>(&rcx19) = reinterpret_cast<uint1_t>(rdx7->f1d8 == 2);
                rdx7->f1f0 = rcx19;
                rdx7 = reinterpret_cast<struct s20*>(reinterpret_cast<int64_t>(rdx7) + 0x200);
            } while (r9_4 != rdx7);
        }
    }
    r8_20 = rdi->f230;
    rdx21 = reinterpret_cast<struct s18*>(reinterpret_cast<int64_t>(rdi->f228) + 0x68);
    if (rdx21 != r8_20) {
        do {
            rdx21->f30->f30 = rdx21->f50;
            rdx21 = reinterpret_cast<struct s18*>(reinterpret_cast<int64_t>(rdx21) + 0x68);
        } while (r8_20 != rdx21);
    }
    if (rax3 != r9_4) {
        while (1) {
            if (!rax3->f30) 
                goto addr_400f30_15;
            if (rax3->f8->f60 < 0) {
                if (rax3->f10->f60 > 0) {
                    addr_400f30_15:
                    rax3 = reinterpret_cast<struct s20*>(reinterpret_cast<int64_t>(rax3) + 64);
                    if (r9_4 != rax3) 
                        continue; else 
                        break;
                }
            } else {
                if (!rax3->f8->f60) {
                    goto addr_400f30_15;
                }
            }
            goto addr_400f30_15;
        }
    }
    __asm__("cvtsi2sd xmm0, r8");
    __asm__("cvtsi2sd xmm1, qword [rdi+0x210]");
    __asm__("mulsd xmm1, xmm0");
    __asm__("xorps xmm0, xmm0");
    __asm__("cvtsi2sd xmm0, rdx");
    __asm__("addsd xmm0, xmm1");
    return;
}

int64_t fopen = 0x4008c6;

int64_t fun_4008c0() {
    goto fopen;
}

struct s25 {
    int64_t f0;
    struct s24* f8;
    struct s24* f10;
    int32_t f18;
};

struct s24 {
    int64_t f0;
    int32_t f8;
    signed char[4] pad16;
    int64_t* f10;
    int64_t f18;
    int64_t f20;
    signed char[8] pad48;
    int64_t f30;
    signed char[24] pad80;
    int64_t f50;
    int64_t f58;
    signed char[8] pad104;
    int64_t f68;
    int32_t f70;
    signed char[4] pad120;
    int64_t f78;
    struct s24* f80;
    int64_t f88;
    struct s24* f90;
    struct s25* f98;
};

struct s26 {
    signed char[24] pad24;
    int32_t f18;
    signed char[60] pad88;
    int32_t f58;
    signed char[60] pad152;
    int32_t f98;
    signed char[60] pad216;
    int32_t fd8;
};

struct s23 {
    signed char[400] pad400;
    int64_t f190;
    signed char[144] pad552;
    struct s24* f228;
    int64_t* f230;
    struct s26* f238;
    struct s26* f240;
    struct s25* f248;
};

int64_t primal_start_artificial(struct s23* rdi, void** rsi, void* rdx) {
    struct s24* r10_4;
    int64_t* r8_5;
    struct s26* rdx6;
    struct s26* rsi7;
    uint64_t r9_8;
    uint64_t rcx9;
    uint64_t rcx10;
    int64_t rcx11;
    int64_t* rdx12;
    struct s25* rsi13;
    struct s24* rcx14;
    struct s24* rdx15;
    struct s24* rdi16;

    r10_4 = rdi->f228;
    r8_5 = &r10_4->f68;
    r10_4->f30 = 0;
    r10_4->f18 = 0;
    r10_4->f10 = r8_5;
    __asm__("pxor xmm0, xmm0");
    __asm__("movdqu [r10+0x20], xmm0");
    r10_4->f58 = rdi->f190 + 1;
    r10_4->f8 = 0;
    r10_4->f0 = 0xfffffffffa0a1f00;
    r10_4->f50 = 0;
    rdx6 = rdi->f238;
    rsi7 = rdi->f240;
    if (rdx6 != rsi7) {
        r9_8 = reinterpret_cast<uint64_t>(reinterpret_cast<int64_t>(rsi7) - 64 - reinterpret_cast<int64_t>(rdx6));
        *reinterpret_cast<uint32_t*>(&rcx9) = (*reinterpret_cast<uint32_t*>(&r9_8) >> 6) + 1;
        *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rcx9) + 4) = 0;
        rcx10 = rcx9 & 3;
        if (rcx10) {
            rcx11 = reinterpret_cast<int64_t>(-rcx10);
            do {
                if (rdx6->f18 != -1) {
                    rdx6->f18 = 1;
                }
                rdx6 = reinterpret_cast<struct s26*>(reinterpret_cast<int64_t>(rdx6) + 64);
                ++rcx11;
            } while (rcx11);
        }
        if (r9_8 >= 0xc0) {
            do {
                if (rdx6->f18 != -1) {
                    rdx6->f18 = 1;
                }
                if (rdx6->f58 != -1) {
                    rdx6->f58 = 1;
                }
                if (rdx6->f98 != -1) {
                    rdx6->f98 = 1;
                }
                if (rdx6->fd8 != -1) {
                    rdx6->fd8 = 1;
                }
                rdx6 = reinterpret_cast<struct s26*>(reinterpret_cast<int64_t>(rdx6) + 0x100);
            } while (rsi7 != rdx6);
        }
    }
    if (r8_5 == rdi->f230) {
        rdx12 = &r10_4->f20;
    } else {
        rsi13 = rdi->f248;
        rcx14 = reinterpret_cast<struct s24*>(rdi->f230 - 13);
        __asm__("movd xmm0, rdx");
        __asm__("pslldq xmm0, 0x8");
        rdx15 = r10_4;
        do {
            rdi16 = rdx15;
            rdx15 = reinterpret_cast<struct s24*>(&rdi16->f68);
            rdi16->f98 = rsi13;
            rdi16->f80 = r10_4;
            rdi16->f78 = 0;
            rdi16->f88 = reinterpret_cast<int64_t>(rdi16) + 0xd0;
            rdi16->f90 = rdi16;
            rsi13->f0 = 0x5f5e100;
            rsi13->f18 = 0;
            rdi16->f70 = 1;
            rdi16->f68 = 0;
            rsi13->f8 = rdx15;
            rsi13->f10 = r10_4;
            __asm__("movdqu [rdi+0xb8], xmm0");
            rsi13 = reinterpret_cast<struct s25*>(reinterpret_cast<int64_t>(rsi13) + 64);
        } while (rcx14 != rdx15);
        rdx12 = &rdx15->f20;
    }
    *rdx12 = 0;
    r10_4->f90 = reinterpret_cast<struct s24*>(0);
    return 0;
}

void** g407e58 = reinterpret_cast<void**>(0);

void** g407f08 = reinterpret_cast<void**>(0);

int64_t g407e68 = 0;

void** g407f18 = reinterpret_cast<void**>(0);

int64_t global_opt(struct s23* rdi, void** rsi, void* rdx) {
    int64_t r14_4;
    void** rsi5;
    void** rsi6;
    int1_t zf7;
    void** rax8;
    void** rax9;
    void** rsi10;

    r14_4 = -6;
    do {
        rsi5 = g407e58;
        fun_400840("active arcs                : %ld\n", rsi5);
        primal_net_simplex(0x407cb0, rsi5);
        rsi6 = g407f08;
        fun_400840("simplex iterations         : %ld\n", rsi6);
        flow_cost(0x407cb0, rsi6);
        fun_400840("objective value            : %0.0f\n", rsi6);
        ++r14_4;
        if (!r14_4) 
            break;
        zf7 = g407e68 == 0;
        if (!zf7 && (rsi6 = reinterpret_cast<void**>(0xffffffffffffffff), rax8 = suspend_impl(0x407cb0, 0xffffffffffffffff, 0), !!rax8)) {
            rsi6 = rax8;
            fun_400840("erased arcs                : %ld\n", rsi6);
        }
        rax9 = price_out_impl(0x407cb0, rsi6);
        if (!rax9) 
            break;
        fun_400840("new implicit arcs          : %ld\n", rax9);
    } while (reinterpret_cast<int32_t>(rax9) >= reinterpret_cast<int32_t>(0));
    goto addr_400ada_7;
    addr_400aee_8:
    rsi10 = g407f18;
    fun_400840("checksum                   : %ld\n", rsi10);
    return 0;
    addr_400ada_7:
    fun_400850("not enough memory, exit(-1)", rax9);
    fun_400860(0xffffffff, rax9);
    goto addr_400aee_8;
}

struct s28 {
    signed char[96] pad96;
    int32_t f60;
};

struct s27 {
    void* f0;
    signed char[8] pad16;
    struct s28* f10;
    signed char[8] pad32;
    struct s27* f20;
    signed char[8] pad48;
    int64_t f30;
};

void fun_400930(int64_t rdi, void** rsi);

int64_t write_circulations(int64_t rdi, void** rsi, void* rdx) {
    void** rbx4;
    void** rbp5;
    struct s0* r12_6;
    void** rsi7;
    int64_t rax8;
    int64_t r15_9;
    int64_t r14_10;
    struct s27* r13_11;
    struct s27* r12_12;
    struct s27* rbp13;
    struct s27* rax14;

    rbx4 = rsi;
    rbp5 = *reinterpret_cast<void***>(rbx4 + 0x6e);
    r12_6 = *reinterpret_cast<struct s0**>(rbx4 + 0x90);
    *reinterpret_cast<int32_t*>(&rsi7) = reinterpret_cast<int32_t>("w");
    *reinterpret_cast<int32_t*>(&rsi7 + 1) = 0;
    rax8 = fun_4008c0();
    r15_9 = rax8;
    r14_10 = -1;
    if (!r15_9) {
        addr_402472_2:
        return r14_10;
    } else {
        refresh_neighbour_lists(rbx4, "w");
        r13_11 = *reinterpret_cast<struct s27**>(reinterpret_cast<uint64_t>(*reinterpret_cast<struct s5**>(rbx4 + 0x8a)) + *reinterpret_cast<int64_t*>(rbx4 + 100) * 0x68 + 56);
        if (!r13_11) {
            addr_40245d_4:
            fun_400900(r15_9, rsi7);
            *reinterpret_cast<int32_t*>(&r14_10) = 0;
            *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&r14_10) + 4) = 0;
            goto addr_402472_2;
        } else {
            r12_12 = reinterpret_cast<struct s27*>(reinterpret_cast<uint64_t>(r12_6) - (reinterpret_cast<uint32_t>(rbp5) << 6));
            do {
                if (r13_11->f30) {
                    fun_4008a0("()\n", 3, 1, r15_9);
                    rbp13 = r13_11;
                    do {
                        if (reinterpret_cast<uint64_t>(rbp13) >= reinterpret_cast<uint64_t>(r12_12)) {
                            fun_4008a0("***\n", 4, 1, r15_9);
                        }
                        *reinterpret_cast<int32_t*>(&rsi7) = reinterpret_cast<int32_t>("%d\n");
                        *reinterpret_cast<int32_t*>(&rsi7 + 1) = 0;
                        fun_400930(r15_9, "%d\n");
                        rax14 = *reinterpret_cast<struct s27**>(reinterpret_cast<int64_t>(rbp13->f10) + *reinterpret_cast<uint64_t*>(rbx4 + 0x66) * 0x68 + 56);
                        if (!rax14) 
                            goto addr_402414_11;
                        do {
                            if (rax14->f30) 
                                break;
                            rax14 = rax14->f20;
                        } while (rax14);
                        goto addr_40246a_14;
                        *reinterpret_cast<int32_t*>(&rbp13) = 0;
                        *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rbp13) + 4) = 0;
                        if (rax14->f10->f60) {
                            rbp13 = rax14;
                        }
                    } while (rbp13);
                }
                r13_11 = r13_11->f20;
            } while (r13_11);
            goto addr_40245d_4;
        }
    }
    addr_402414_11:
    addr_40246a_14:
    fun_400900(r15_9, "%d\n");
    goto addr_402472_2;
}

int64_t primal_feasible(struct s9* rdi, void** rsi, void** rdx, void** rcx, void** r8, void** r9) {
    struct s9* r15_7;
    struct s11* rbp8;
    struct s11* rbx9;
    int64_t rax10;
    int64_t rbx11;
    uint64_t r12_12;
    uint64_t r14_13;
    void** r13_14;
    void** rax15;

    r15_7 = rdi;
    rbp8 = r15_7->f230;
    rbx9 = reinterpret_cast<struct s11*>(reinterpret_cast<int64_t>(r15_7->f228) + 0x68);
    if (reinterpret_cast<uint64_t>(rbx9) >= reinterpret_cast<uint64_t>(rbp8)) {
        *reinterpret_cast<int32_t*>(&rax10) = 0;
        *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rax10) + 4) = 0;
        *reinterpret_cast<int32_t*>(&rbx11) = 1;
        *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rbx11) + 4) = 0;
    } else {
        r12_12 = r15_7->f248;
        r14_13 = r15_7->f250;
        do {
            r13_14 = rbx9->f50;
            if (rbx9->f30 < r12_12 || rbx9->f30 >= r14_13) {
                if (reinterpret_cast<int32_t>(r13_14) < reinterpret_cast<int32_t>(-reinterpret_cast<uint32_t>(r15_7->f200))) 
                    goto addr_4011e6_6;
                if (reinterpret_cast<int32_t>(reinterpret_cast<uint32_t>(r13_14) + 0xffffffffffffffff) > reinterpret_cast<int32_t>(r15_7->f200)) 
                    goto addr_4011e6_6;
            } else {
                rax15 = reinterpret_cast<void**>(-reinterpret_cast<uint32_t>(r13_14));
                if (__intrinsic() != __intrinsic()) {
                    rax15 = r13_14;
                }
                if (reinterpret_cast<int32_t>(rax15) > reinterpret_cast<int32_t>(r15_7->f200)) {
                    fun_400840("PRIMAL NETWORK SIMPLEX: ", rsi, "PRIMAL NETWORK SIMPLEX: ", rsi);
                    *reinterpret_cast<int32_t*>(&rsi) = rbx9->f60;
                    *reinterpret_cast<int32_t*>(&rsi + 1) = 0;
                    fun_400840("artificial arc with nonzero flow, node %d (%ld)\n", rsi, "artificial arc with nonzero flow, node %d (%ld)\n", rsi);
                }
            }
            rbx9 = reinterpret_cast<struct s11*>(reinterpret_cast<uint64_t>(rbx9) + 0x68);
        } while (reinterpret_cast<uint64_t>(rbx9) < reinterpret_cast<uint64_t>(rbp8));
        goto addr_4011d4_13;
    }
    addr_401208_14:
    r15_7->f1e8 = rbx11;
    return rax10;
    addr_4011e6_6:
    *reinterpret_cast<int32_t*>(&rbx11) = 0;
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rbx11) + 4) = 0;
    fun_400840("PRIMAL NETWORK SIMPLEX: ", rsi, "PRIMAL NETWORK SIMPLEX: ", rsi);
    fun_400840("basis primal infeasible (%ld)\n", r13_14, "basis primal infeasible (%ld)\n", r13_14);
    *reinterpret_cast<int32_t*>(&rax10) = 1;
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rax10) + 4) = 0;
    goto addr_401208_14;
    addr_4011d4_13:
    *reinterpret_cast<int32_t*>(&rbx11) = 1;
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rbx11) + 4) = 0;
    *reinterpret_cast<int32_t*>(&rax10) = 0;
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rax10) + 4) = 0;
    goto addr_401208_14;
}

int64_t fflush = 0x400926;

void fun_400920(int64_t rdi, void** rsi) {
    goto fflush;
}

int64_t realloc = 0x400916;

struct s0* fun_400910(struct s0* rdi) {
    goto realloc;
}

int64_t fprintf = 0x400936;

void fun_400930(int64_t rdi, void** rsi) {
    goto fprintf;
}

signed char initialize = 0;

int64_t g405b98 = 0;

uint64_t nr_group = 0;

int64_t g405ba0 = 0;

uint64_t group_pos = 0;

uint64_t basket_size = 0;

struct s29 {
    int64_t f0;
    int64_t* f8;
    int64_t* f10;
    int32_t f18;
};

struct s30 {
    struct s29* f0;
    int64_t f8;
    int64_t f10;
};

struct s31 {
    void** f0;
    signed char[4] pad8;
    void* f8;
    void* f10;
};

struct s32 {
    struct s8* f0;
    void** f8;
};

struct s32* g4050b8 = reinterpret_cast<struct s32*>(0);

struct s8* primal_bea_mpp(int64_t rdi, void** rsi, void** rdx, void** rcx, void** r8, void** r9) {
    void** r14_7;
    void** r11_8;
    signed char al9;
    int64_t rax10;
    uint64_t r9_11;
    uint64_t r15_12;
    uint64_t r10_13;
    uint64_t rdx14;
    uint64_t rdi15;
    int64_t rbx16;
    struct s30* rbp17;
    int64_t rcx18;
    int1_t less19;
    void* rdx20;
    uint64_t r12_21;
    void** rbx22;
    void* rdi23;
    struct s31* rax24;
    void* rcx25;
    struct s8* rax26;
    struct s32* rax27;

    r14_7 = rcx;
    r11_8 = rdx;
    al9 = initialize;
    if (!al9) {
        __asm__("movdqa xmm5, [rip+0x657]");
        rax10 = 0xfffffffffffff520;
        __asm__("movdqa xmm1, [rip+0x658]");
        __asm__("movd xmm2, rcx");
        __asm__("pshufd xmm2, xmm2, 0x44");
        __asm__("movdqa xmm8, [rip+0x650]");
        __asm__("movdqa xmm9, [rip+0x657]");
        __asm__("movdqa xmm10, [rip+0x65e]");
        __asm__("movdqa xmm11, [rip+0x665]");
        __asm__("movdqa xmm7, [rip+0x66d]");
        __asm__("movdqa xmm3, [rip+0x675]");
        do {
            __asm__("movdqa xmm0, xmm5");
            __asm__("pmuludq xmm0, xmm1");
            __asm__("paddq xmm0, xmm2");
            __asm__("movdqa xmm4, xmm5");
            __asm__("psrlq xmm4, 0x20");
            __asm__("pmuludq xmm4, xmm1");
            __asm__("psllq xmm4, 0x20");
            __asm__("paddq xmm4, xmm0");
            __asm__("movdqa xmm0, xmm4");
            __asm__("paddq xmm0, xmm8");
            __asm__("movdqu [rax+0x405b98], xmm4");
            __asm__("movdqu [rax+0x405ba8], xmm0");
            __asm__("movdqa xmm0, xmm4");
            __asm__("paddq xmm0, xmm9");
            __asm__("movdqa xmm6, xmm4");
            __asm__("paddq xmm6, xmm10");
            __asm__("movdqu [rax+0x405bb8], xmm0");
            __asm__("movdqu [rax+0x405bc8], xmm6");
            __asm__("movdqa xmm0, xmm4");
            __asm__("paddq xmm0, xmm11");
            __asm__("paddq xmm4, xmm7");
            __asm__("movdqu [rax+0x405bd8], xmm0");
            __asm__("movdqu [rax+0x405be8], xmm4");
            __asm__("paddq xmm5, xmm3");
            rax10 = rax10 + 96;
        } while (rax10);
        g405b98 = 0x407c68;
        r9_11 = (reinterpret_cast<int64_t>(__intrinsic()) >> 7) + (__intrinsic() >> 63) + 1;
        nr_group = r9_11;
        g405ba0 = 0x407c80;
        initialize = 1;
        group_pos = 0;
        basket_size = 0;
        *reinterpret_cast<int32_t*>(&r15_12) = 0;
        *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&r15_12) + 4) = 0;
        *reinterpret_cast<int32_t*>(&r10_13) = 0;
        *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&r10_13) + 4) = 0;
    } else {
        rdx14 = basket_size;
        if (reinterpret_cast<int64_t>(rdx14) >= reinterpret_cast<int64_t>(2)) {
            *reinterpret_cast<int32_t*>(&rdi15) = 2;
            *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rdi15) + 4) = 0;
            *reinterpret_cast<int32_t*>(&r15_12) = 0;
            *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&r15_12) + 4) = 0;
            do {
                rbx16 = (**reinterpret_cast<struct s29***>(rdi15 * 8 + 0x4050b0))->f0 - *(**reinterpret_cast<struct s29***>(rdi15 * 8 + 0x4050b0))->f8 + *(**reinterpret_cast<struct s29***>(rdi15 * 8 + 0x4050b0))->f10;
                if (rbx16 < 0) {
                    if ((**reinterpret_cast<struct s29***>(rdi15 * 8 + 0x4050b0))->f18 == 1) {
                        addr_402c8b_9:
                        rbp17 = *reinterpret_cast<struct s30**>(r15_12 * 8 + 0x4050b8);
                        rbp17->f0 = **reinterpret_cast<struct s29***>(rdi15 * 8 + 0x4050b0);
                        ++r15_12;
                        rbp17->f8 = rbx16;
                        rcx18 = -rbx16;
                        if (__intrinsic() != __intrinsic()) {
                            rcx18 = rbx16;
                        }
                    } else {
                        goto addr_402cad_12;
                    }
                } else {
                    if (!rbx16) 
                        goto addr_402cad_12;
                    if ((**reinterpret_cast<struct s29***>(rdi15 * 8 + 0x4050b0))->f18 != 2) 
                        goto addr_402cad_12; else 
                        goto addr_402c8b_9;
                }
                rbp17->f10 = rcx18;
                addr_402cad_12:
                if (rdi15 > 49) 
                    goto addr_402cc8_16;
                less19 = reinterpret_cast<int64_t>(rdi15) < reinterpret_cast<int64_t>(rdx14);
                ++rdi15;
            } while (less19);
            goto addr_402cbc_18;
        } else {
            *reinterpret_cast<int32_t*>(&r15_12) = 0;
            *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&r15_12) + 4) = 0;
            goto addr_402cc8_16;
        }
    }
    addr_402cdd_20:
    rdx20 = reinterpret_cast<void*>(r9_11 << 6);
    r12_21 = r10_13;
    do {
        rbx22 = reinterpret_cast<void**>((r12_21 << 6) + reinterpret_cast<uint32_t>(rsi));
        if (reinterpret_cast<uint32_t>(rbx22) < reinterpret_cast<uint32_t>(r11_8)) {
            while (1) {
                if (reinterpret_cast<uint1_t>(reinterpret_cast<int32_t>(*reinterpret_cast<void***>(rbx22 + 6)) < reinterpret_cast<int32_t>(0)) | reinterpret_cast<uint1_t>(*reinterpret_cast<void***>(rbx22 + 6) == 0)) 
                    goto addr_402d10_23;
                rdi23 = reinterpret_cast<void*>(reinterpret_cast<uint64_t>(reinterpret_cast<uint32_t>(*reinterpret_cast<void***>(rbx22)) - reinterpret_cast<uint32_t>(*reinterpret_cast<void***>(*reinterpret_cast<void***>(rbx22 + 2)))) + reinterpret_cast<uint32_t>(*reinterpret_cast<void***>(*reinterpret_cast<void***>(rbx22 + 4))));
                if (reinterpret_cast<int64_t>(rdi23) < reinterpret_cast<int64_t>(0)) {
                    if (!reinterpret_cast<int1_t>(*reinterpret_cast<void***>(rbx22 + 6) == 1)) {
                        addr_402d10_23:
                        rbx22 = reinterpret_cast<void**>(reinterpret_cast<uint32_t>(rbx22) + reinterpret_cast<uint64_t>(rdx20));
                        if (reinterpret_cast<uint32_t>(rbx22) >= reinterpret_cast<uint32_t>(r11_8)) 
                            break; else 
                            continue;
                    } else {
                        addr_402d45_26:
                        rax24 = *reinterpret_cast<struct s31**>(r15_12 * 8 + 0x4050b8);
                        ++r15_12;
                        basket_size = r15_12;
                        rax24->f0 = rbx22;
                        rax24->f8 = rdi23;
                        rcx25 = reinterpret_cast<void*>(-reinterpret_cast<uint64_t>(rdi23));
                        if (__intrinsic() != __intrinsic()) {
                            rcx25 = rdi23;
                        }
                    }
                    rax24->f10 = rcx25;
                    goto addr_402d10_23;
                } else {
                    if (!rdi23) 
                        goto addr_402d10_23;
                    if (*reinterpret_cast<void***>(rbx22 + 6) == 2) 
                        goto addr_402d45_26;
                    goto addr_402d10_23;
                }
            }
        }
        ++r12_21;
        if (r12_21 == r9_11) {
            r12_21 = 0;
        }
    } while (reinterpret_cast<int64_t>(r15_12) <= reinterpret_cast<int64_t>(49) && r12_21 != r10_13);
    group_pos = r12_21;
    if (!r15_12) {
        initialize = 0;
        *reinterpret_cast<void***>(r14_7) = reinterpret_cast<void**>(0);
        *reinterpret_cast<int32_t*>(&rax26) = 0;
        *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rax26) + 4) = 0;
    } else {
        sort_basket(1, r15_12);
        rax27 = g4050b8;
        *reinterpret_cast<void***>(r14_7) = rax27->f8;
        rax26 = rax27->f0;
    }
    return rax26;
    addr_402cc8_16:
    basket_size = r15_12;
    r10_13 = group_pos;
    r9_11 = nr_group;
    goto addr_402cdd_20;
    addr_402cbc_18:
    goto addr_402cc8_16;
}

int64_t stderr = 0;

int64_t dual_feasible(struct s9* rdi, void** rsi, void** rdx, void** rcx, void** r8, void** r9) {
    void** rax7;
    void** rcx8;
    int64_t rbx9;
    void** rdx10;
    int64_t rcx11;
    int64_t rcx12;

    rax7 = rdi->f238;
    rcx8 = rdi->f240;
    *reinterpret_cast<int32_t*>(&rbx9) = 0;
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rbx9) + 4) = 0;
    if (reinterpret_cast<uint32_t>(rax7) < reinterpret_cast<uint32_t>(rcx8)) {
        do {
            rdx10 = reinterpret_cast<void**>(reinterpret_cast<uint64_t>(reinterpret_cast<uint32_t>(*reinterpret_cast<void***>(rax7)) - reinterpret_cast<uint32_t>(*reinterpret_cast<void***>(*reinterpret_cast<void***>(rax7 + 2)))) + reinterpret_cast<uint32_t>(*reinterpret_cast<void***>(*reinterpret_cast<void***>(rax7 + 4))));
            if (reinterpret_cast<uint32_t>(*reinterpret_cast<void***>(rax7 + 6)) >= 2) {
                if (!reinterpret_cast<int1_t>(*reinterpret_cast<void***>(rax7 + 6) == 2)) 
                    continue;
                if (reinterpret_cast<int32_t>(rdx10) > reinterpret_cast<int32_t>(rdi->f200)) 
                    break;
            } else {
                if (reinterpret_cast<int32_t>(rdx10) < reinterpret_cast<int32_t>(-static_cast<int64_t>(reinterpret_cast<uint32_t>(rdi->f200)))) 
                    goto addr_40126e_6;
            }
            rax7 = rax7 + 16;
        } while (reinterpret_cast<uint32_t>(rax7) < reinterpret_cast<uint32_t>(rcx8));
        goto addr_4012b6_8;
    } else {
        goto addr_4012b6_8;
    }
    addr_40127b_10:
    rcx11 = stderr;
    *reinterpret_cast<int32_t*>(&rbx9) = 1;
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rbx9) + 4) = 0;
    fun_4008a0("DUAL NETWORK SIMPLEX: ", 22, 1, rcx11);
    rcx12 = stderr;
    fun_4008a0("basis dual infeasible\n", 22, 1, rcx12);
    addr_4012b6_8:
    return rbx9;
    addr_40126e_6:
    goto addr_40127b_10;
}

void _fini() {
    return;
}

void fun_4009fb() {
    return;
}

int64_t g407ec0 = 0;

void** g407e48 = reinterpret_cast<void**>(0);

int64_t main(int32_t edi, void** rsi) {
    uint32_t ebp3;
    void** rsi4;
    int64_t rax5;
    void** rsi6;
    int64_t rax7;
    int64_t rax8;

    ebp3 = 0xffffffff;
    if (edi >= 2) {
        fun_400850("\nMCF SPEC CPU2006 version 1.10", rsi);
        fun_400850("Copyright (c) 1998-2000 Zuse Institut Berlin (ZIB)", rsi);
        fun_400850("Copyright (c) 2000-2002 Andreas Loebel & ZIB", rsi);
        fun_400850("Copyright (c) 2003-2005 Andreas Loebel", rsi);
        fun_400870(10);
        fun_400880(0x407cb0);
        g407ec0 = 0x989680;
        rsi4 = *reinterpret_cast<void***>(rsi + 2);
        fun_400890(0x407cb0, rsi4, 0x270);
        rax5 = read_min(0x407cb0, rsi4, 0x270);
        if (!rax5) {
            rsi6 = g407e48;
            fun_400840("nodes                      : %ld\n", rsi6, "nodes                      : %ld\n", rsi6);
            primal_start_artificial(0x407cb0, rsi6, 0x270);
            global_opt(0x407cb0, rsi6, 0x270);
            fun_400850("done", rsi6, "done", rsi6);
            rax7 = write_circulations("mcf.out", 0x407cb0, 0x270);
            getfree(0x407cb0, 0x407cb0, 0x270);
            ebp3 = 0xffffffff - (0xffffffff + reinterpret_cast<uint1_t>(0xffffffff < 0xffffffff + reinterpret_cast<uint1_t>(!!rax7)));
        } else {
            fun_400850("read error, exit", rsi4, "read error, exit", rsi4);
            getfree(0x407cb0, rsi4, 0x270);
        }
    }
    *reinterpret_cast<uint32_t*>(&rax8) = ebp3;
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rax8) + 4) = 0;
    return rax8;
}

struct s34 {
    signed char[96] pad96;
    int32_t f60;
};

struct s35 {
    signed char[96] pad96;
    int32_t f60;
};

struct s33 {
    signed char[8] pad8;
    struct s34* f8;
    struct s35* f10;
    signed char[24] pad48;
    int64_t f30;
};

void fun_4010db(int64_t rdi) {
    struct s33* rax2;
    struct s33* tmp64_3;
    struct s33* r9_4;

    goto addr_4010e0_2;
    addr_4010fa_3:
    __asm__("cvtsi2sd xmm0, r8");
    __asm__("cvtsi2sd xmm1, qword [rdi+0x210]");
    __asm__("mulsd xmm1, xmm0");
    __asm__("xorps xmm0, xmm0");
    __asm__("cvtsi2sd xmm0, rdx");
    __asm__("addsd xmm0, xmm1");
    return;
    while (rax2 = tmp64_3, r9_4 != rax2) {
        if (!rax2->f30) 
            continue;
        if (rax2->f8->f60 < 0) {
            addr_4010e0_2:
            if (rax2->f10->f60 > 0) 
                continue;
        } else {
            if (!rax2->f8->f60) {
                continue;
            }
        }
    }
    goto addr_4010fa_3;
}

struct s36 {
    signed char[448] pad448;
    int64_t f1c0;
};

struct s37 {
    int64_t f0;
    int64_t f8;
    int64_t f10;
    signed char[24] pad48;
    int64_t f30;
    int64_t f38;
    signed char[48] pad112;
    int64_t f70;
    signed char[56] pad176;
    int64_t fb0;
};

void replace_weaker_arc(struct s36* rdi, struct s37* rsi, int64_t rdx, int64_t rcx, int64_t r8, int64_t r9) {
    int64_t rbx7;
    int64_t r11_8;
    int64_t r10_9;
    int64_t rdi10;
    int64_t r14_11;
    void* rax12;
    int64_t r11_13;
    void* rdi14;
    int64_t rax15;
    void* rdi16;

    rsi->f8 = rdx;
    rsi->f10 = rcx;
    rsi->f38 = r8;
    rsi->f0 = r8;
    rsi->f30 = r9;
    *reinterpret_cast<int32_t*>(&rbx7) = 0;
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rbx7) + 4) = 0;
    *reinterpret_cast<unsigned char*>(&rbx7) = reinterpret_cast<uint1_t>(rsi->f70 > rsi->fb0);
    r11_8 = 3 - rbx7;
    r10_9 = rdi->f1c0;
    if (r11_8 <= r10_9) {
        *reinterpret_cast<int32_t*>(&rdi10) = 1;
        *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rdi10) + 4) = 0;
        do {
            r14_11 = r11_8;
            rax12 = reinterpret_cast<void*>(r14_11 - 1 << 6);
            r11_13 = *reinterpret_cast<int64_t*>(reinterpret_cast<int64_t>(rsi) + reinterpret_cast<int64_t>(rax12) + 48);
            if (r11_13 <= r9) 
                break;
            rdi14 = reinterpret_cast<void*>(rdi10 << 6);
            *reinterpret_cast<int64_t*>(reinterpret_cast<int64_t>(rsi) + reinterpret_cast<int64_t>(rdi14) - 48) = *reinterpret_cast<int64_t*>(reinterpret_cast<int64_t>(rsi) + reinterpret_cast<int64_t>(rax12) + 16);
            __asm__("movups xmm0, [rsi+rax]");
            __asm__("movups [rsi+rdi-0x40], xmm0");
            *reinterpret_cast<int64_t*>(reinterpret_cast<int64_t>(rsi) + reinterpret_cast<int64_t>(rdi14) - 8) = *reinterpret_cast<int64_t*>(reinterpret_cast<int64_t>(rsi) + reinterpret_cast<int64_t>(rax12));
            *reinterpret_cast<int64_t*>(reinterpret_cast<int64_t>(rsi) + reinterpret_cast<int64_t>(rdi14) - 16) = r11_13;
            *reinterpret_cast<int64_t*>(reinterpret_cast<int64_t>(rsi) + reinterpret_cast<int64_t>(rax12) + 8) = rdx;
            *reinterpret_cast<int64_t*>(reinterpret_cast<int64_t>(rsi) + reinterpret_cast<int64_t>(rax12) + 16) = rcx;
            *reinterpret_cast<int64_t*>(reinterpret_cast<int64_t>(rsi) + reinterpret_cast<int64_t>(rax12)) = r8;
            *reinterpret_cast<int64_t*>(reinterpret_cast<int64_t>(rsi) + reinterpret_cast<int64_t>(rax12) + 56) = r8;
            *reinterpret_cast<int64_t*>(reinterpret_cast<int64_t>(rsi) + reinterpret_cast<int64_t>(rax12) + 48) = r9;
            r11_8 = r14_11 + r14_11;
            rax15 = r14_11 + r14_11 + 1;
            if (rax15 <= r10_9) {
                rdi16 = reinterpret_cast<void*>(r11_8 << 6);
                if (*reinterpret_cast<int64_t*>(reinterpret_cast<int64_t>(rsi) + reinterpret_cast<int64_t>(rdi16) - 16) >= *reinterpret_cast<int64_t*>(reinterpret_cast<int64_t>(rsi) + reinterpret_cast<int64_t>(rdi16) + 48)) {
                    rax15 = r11_8;
                }
                r11_8 = rax15;
            }
            rdi10 = r14_11;
        } while (r11_8 <= r10_9);
    }
    return;
}

void __libc_csu_fini() {
    return;
}

int64_t fun_400991() {
    if (1 || 1) {
        return 0;
    } else {
        goto 0;
    }
}

signed char g4050a0 = 0;

int64_t __do_global_dtors_aux() {
    int1_t zf1;
    int64_t rax2;

    zf1 = g4050a0 == 0;
    if (!zf1) 
        goto 0x400a00;
    rax2 = deregister_tm_clones();
    g4050a0 = 1;
    return rax2;
}

void frame_dummy() {
    goto 0x4009a0;
}

int64_t g404ff8 = 0;

void fun_400846() {
    goto g404ff8;
}

void fun_400856() {
    goto 0x400830;
}

void fun_400866() {
    goto 0x400830;
}

void fun_400876() {
    goto 0x400830;
}

void fun_400886() {
    goto 0x400830;
}

void fun_400896() {
    goto 0x400830;
}

struct s40 {
    signed char[48] pad48;
    int64_t f30;
};

struct s39 {
    signed char[48] pad48;
    struct s40* f30;
    signed char[24] pad80;
    int64_t f50;
};

struct s41 {
    signed char[24] pad24;
    int32_t f18;
    signed char[20] pad48;
    int64_t f30;
    signed char[32] pad88;
    int32_t f58;
    signed char[20] pad112;
    int64_t f70;
    signed char[32] pad152;
    int32_t f98;
    signed char[20] pad176;
    int64_t fb0;
    signed char[32] pad216;
    int32_t fd8;
    signed char[20] pad240;
    int64_t ff0;
    signed char[32] pad280;
    int32_t f118;
    signed char[20] pad304;
    int64_t f130;
    signed char[32] pad344;
    int32_t f158;
    signed char[20] pad368;
    int64_t f170;
    signed char[32] pad408;
    int32_t f198;
    signed char[20] pad432;
    int64_t f1b0;
    signed char[32] pad472;
    int32_t f1d8;
    signed char[20] pad496;
    int64_t f1f0;
};

struct s38 {
    signed char[552] pad552;
    void* f228;
    struct s39* f230;
    struct s41* f238;
    struct s41* f240;
};

void flow_org_cost(struct s38* rdi) {
    struct s41* rax2;
    struct s41* r9_3;
    uint64_t r8_4;
    uint64_t rsi5;
    struct s41* rdx6;
    uint64_t rsi7;
    int64_t rsi8;
    int64_t rcx9;
    int32_t ecx10;
    int64_t rsi11;
    int64_t rsi12;
    int64_t rcx13;
    int64_t rcx14;
    int64_t rcx15;
    int64_t rcx16;
    int64_t rcx17;
    int64_t rcx18;
    struct s39* r8_19;
    struct s39* rdx20;

    rax2 = rdi->f238;
    r9_3 = rdi->f240;
    if (rax2 != r9_3) {
        r8_4 = reinterpret_cast<uint64_t>(reinterpret_cast<int64_t>(r9_3) - 64 - reinterpret_cast<int64_t>(rax2));
        *reinterpret_cast<uint32_t*>(&rsi5) = (*reinterpret_cast<uint32_t*>(&r8_4) >> 6) + 1;
        *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rsi5) + 4) = 0;
        rdx6 = rax2;
        rsi7 = rsi5 & 7;
        if (rsi7) {
            rsi8 = reinterpret_cast<int64_t>(-rsi7);
            rdx6 = rax2;
            do {
                *reinterpret_cast<int32_t*>(&rcx9) = 0;
                *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rcx9) + 4) = 0;
                *reinterpret_cast<unsigned char*>(&rcx9) = reinterpret_cast<uint1_t>(rdx6->f18 == 2);
                rdx6->f30 = rcx9;
                rdx6 = reinterpret_cast<struct s41*>(reinterpret_cast<int64_t>(rdx6) + 64);
                ++rsi8;
            } while (rsi8);
        }
        if (r8_4 >= 0x1c0) {
            do {
                ecx10 = rdx6->f58;
                *reinterpret_cast<int32_t*>(&rsi11) = 0;
                *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rsi11) + 4) = 0;
                *reinterpret_cast<unsigned char*>(&rsi11) = reinterpret_cast<uint1_t>(rdx6->f18 == 2);
                rdx6->f30 = rsi11;
                *reinterpret_cast<int32_t*>(&rsi12) = 0;
                *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rsi12) + 4) = 0;
                *reinterpret_cast<unsigned char*>(&rsi12) = reinterpret_cast<uint1_t>(ecx10 == 2);
                rdx6->f70 = rsi12;
                *reinterpret_cast<int32_t*>(&rcx13) = 0;
                *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rcx13) + 4) = 0;
                *reinterpret_cast<unsigned char*>(&rcx13) = reinterpret_cast<uint1_t>(rdx6->f98 == 2);
                rdx6->fb0 = rcx13;
                *reinterpret_cast<int32_t*>(&rcx14) = 0;
                *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rcx14) + 4) = 0;
                *reinterpret_cast<unsigned char*>(&rcx14) = reinterpret_cast<uint1_t>(rdx6->fd8 == 2);
                rdx6->ff0 = rcx14;
                *reinterpret_cast<int32_t*>(&rcx15) = 0;
                *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rcx15) + 4) = 0;
                *reinterpret_cast<unsigned char*>(&rcx15) = reinterpret_cast<uint1_t>(rdx6->f118 == 2);
                rdx6->f130 = rcx15;
                *reinterpret_cast<int32_t*>(&rcx16) = 0;
                *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rcx16) + 4) = 0;
                *reinterpret_cast<unsigned char*>(&rcx16) = reinterpret_cast<uint1_t>(rdx6->f158 == 2);
                rdx6->f170 = rcx16;
                *reinterpret_cast<int32_t*>(&rcx17) = 0;
                *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rcx17) + 4) = 0;
                *reinterpret_cast<unsigned char*>(&rcx17) = reinterpret_cast<uint1_t>(rdx6->f198 == 2);
                rdx6->f1b0 = rcx17;
                *reinterpret_cast<int32_t*>(&rcx18) = 0;
                *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rcx18) + 4) = 0;
                *reinterpret_cast<unsigned char*>(&rcx18) = reinterpret_cast<uint1_t>(rdx6->f1d8 == 2);
                rdx6->f1f0 = rcx18;
                rdx6 = reinterpret_cast<struct s41*>(reinterpret_cast<int64_t>(rdx6) + 0x200);
            } while (r9_3 != rdx6);
        }
    }
    r8_19 = rdi->f230;
    rdx20 = reinterpret_cast<struct s39*>(reinterpret_cast<int64_t>(rdi->f228) + 0x68);
    if (rdx20 != r8_19) {
        do {
            rdx20->f30->f30 = rdx20->f50;
            rdx20 = reinterpret_cast<struct s39*>(reinterpret_cast<int64_t>(rdx20) + 0x68);
        } while (r8_19 != rdx20);
    }
    if (rax2 == r9_3) {
    }
}

void fun_4008a6() {
    goto 0x400830;
}

void fun_4008b6() {
    goto 0x400830;
}

void fun_4008d6() {
    goto 0x400830;
}

void fun_4008e6() {
    goto 0x400830;
}

void fun_4008f6() {
    goto 0x400830;
}

void insert_new_arc(int64_t* rdi, uint64_t rsi, int64_t rdx, int64_t rcx, int64_t r8, int64_t r9) {
    uint64_t rax7;
    uint64_t r11_8;
    uint64_t r10_9;
    uint64_t rax10;
    int64_t r15_11;
    uint64_t rsi12;

    rax7 = rsi << 6;
    *reinterpret_cast<int64_t*>(reinterpret_cast<uint64_t>(rdi) + rax7 + 8) = rdx;
    *reinterpret_cast<int64_t*>(reinterpret_cast<uint64_t>(rdi) + rax7 + 16) = rcx;
    *reinterpret_cast<int64_t*>(reinterpret_cast<uint64_t>(rdi) + rax7 + 56) = r8;
    *reinterpret_cast<int64_t*>(reinterpret_cast<uint64_t>(rdi) + rax7) = r8;
    *reinterpret_cast<int64_t*>(reinterpret_cast<uint64_t>(rdi) + rax7 + 48) = r9;
    if (rsi) {
        r11_8 = rsi + 1;
        do {
            r11_8 = reinterpret_cast<uint64_t>(reinterpret_cast<int64_t>(r11_8 + (r11_8 >> 63)) >> 1);
            r10_9 = r11_8 + 0xffffffffffffffff;
            rax10 = r10_9 << 6;
            r15_11 = *reinterpret_cast<int64_t*>(reinterpret_cast<uint64_t>(rdi) + rax10 + 48);
            if (r15_11 >= r9) 
                break;
            rsi12 = rsi << 6;
            *reinterpret_cast<int64_t*>(reinterpret_cast<uint64_t>(rdi) + rsi12 + 16) = *reinterpret_cast<int64_t*>(reinterpret_cast<uint64_t>(rdi) + rax10 + 16);
            __asm__("movups xmm0, [rdi+rax]");
            __asm__("movups [rdi+rsi], xmm0");
            *reinterpret_cast<int64_t*>(reinterpret_cast<uint64_t>(rdi) + rsi12 + 56) = *reinterpret_cast<int64_t*>(reinterpret_cast<uint64_t>(rdi) + rax10);
            *reinterpret_cast<int64_t*>(reinterpret_cast<uint64_t>(rdi) + rsi12 + 48) = r15_11;
            *reinterpret_cast<int64_t*>(reinterpret_cast<uint64_t>(rdi) + rax10 + 8) = rdx;
            *reinterpret_cast<int64_t*>(reinterpret_cast<uint64_t>(rdi) + rax10 + 16) = rcx;
            *reinterpret_cast<int64_t*>(reinterpret_cast<uint64_t>(rdi) + rax10) = r8;
            *reinterpret_cast<int64_t*>(reinterpret_cast<uint64_t>(rdi) + rax10 + 56) = r8;
            *reinterpret_cast<int64_t*>(rax10 + reinterpret_cast<uint64_t>(rdi) + 48) = r9;
            rsi = r10_9;
        } while (r10_9);
    }
    return;
}

void fun_400906() {
    goto 0x400830;
}

struct s42 {
    signed char[24] pad24;
    int32_t f18;
};

int64_t bea_is_dual_infeasible(struct s42* rdi, int64_t rsi) {
    int64_t rax3;

    *reinterpret_cast<int32_t*>(&rax3) = 0;
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rax3) + 4) = 0;
    if (rsi < 0) {
        *reinterpret_cast<unsigned char*>(&rax3) = reinterpret_cast<uint1_t>(rdi->f18 == 1);
        return rax3;
    } else {
        if (rsi) {
            *reinterpret_cast<unsigned char*>(&rax3) = reinterpret_cast<uint1_t>(rdi->f18 == 2);
        }
        return rax3;
    }
}

void __libc_csu_init(int32_t edi, int64_t rsi, int64_t rdx) {
    int64_t r15_4;
    int32_t r13d5;
    int64_t r14_6;
    int64_t rbx7;
    int64_t rdi8;

    r15_4 = rdx;
    r13d5 = edi;
    r14_6 = rsi;
    _init();
    if (!0) {
        *reinterpret_cast<int32_t*>(&rbx7) = 0;
        *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rbx7) + 4) = 0;
        do {
            *reinterpret_cast<int32_t*>(&rdi8) = r13d5;
            *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rdi8) + 4) = 0;
            *reinterpret_cast<int64_t*>(0x404df0 + rbx7 * 8)(rdi8, r14_6, r15_4);
            ++rbx7;
        } while (1 != rbx7);
    }
    return;
}

void fun_4008c6() {
    goto 0x400830;
}

void fun_400926() {
    goto 0x400830;
}

void fun_400916() {
    goto 0x400830;
}

void fun_400936() {
    goto 0x400830;
}

int64_t __libc_start_main = 0;

void _start() {
    void* rsp1;
    int64_t rdx2;
    int64_t rax3;

    rsp1 = reinterpret_cast<void*>(reinterpret_cast<int64_t>(__zero_stack_offset()) + 8);
    __libc_start_main(main, __return_address(), rsp1, __libc_csu_init, __libc_csu_fini, rdx2, (reinterpret_cast<uint64_t>(rsp1) & 0xfffffffffffffff0) - 8 - 8, rax3);
    __asm__("hlt ");
}
