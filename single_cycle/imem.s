        lb x4, 0(x0)
        lh x5, 4(x0)
        lbu x6, 0(x0)
        lhu x7, 4(x0)
        sb x4, 0(x0)
        sh x5, 0(x0)
        lw x8, 8(x0)
        sll x9, x6, x8
        slli x10, x6, 3
        srl x11, x6, x8
        srli x12, x6, 1
        sra x13, x5, x8
        srai x14, x5, 2
        lui x15, -65537
        auipc x16, 262144
        slt x17, x4, x5
        slti x18, x4, 2
        sltu x19, x15, x8
        sltiu x20, x15, 2
        addi x21, x0, 56
        jal x22, 8
        addi x21, x0, 56
        jalr x23, 40(x21)
        addi x21, x0, 56
        bltu x15, x8, -8
        bgeu x15, x8, -8