function T = setInputZ(fourBits)
    
    if (fourBits(1) == 0 && fourBits(2) == 0)
        Re = -3.0;
    endif
    
    if (fourBits(1) == 0 && fourBits(2) == 1)
        Re = (-1.0);
    endif
    
    if (fourBits(1) == 1 && fourBits(2) == 1)
        Re = (1.0);
    endif
    
    if (fourBits(1) == 1 && fourBits(2) == 0)
        Re = (3.0);
    endif
    
    
    
    
    if (fourBits(3) == 0 && fourBits(4) == 0)
        Im = (-3.0);
    endif
    
    if (fourBits(3) == 0 && fourBits(4) == 1)
        Im = (-1.0);
    endif
    
    if (fourBits(3) == 1 && fourBits(4) == 1)
        Im = (1.0);
    endif
    
    if (fourBits(3) == 1 && fourBits(4) == 0)
        Im = (3.0);
    endif

    T = Re + Im*i;
    
endfunction