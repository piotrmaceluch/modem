function outputBits = setOutputBits(amplitude, phase)

    a = amplitude *     cos(phase);
    b = amplitude * i * sin(phase);
    z = a + b;
    
    if (real(z) < -2 )
        outputBits(1) = 0;
        outputBits(2) = 0;
    endif
    
    if (real(z) >= -2 && real(z) < 0)
        outputBits(1) = 0;
        outputBits(2) = 1;
    endif
  
    if (real(z) >= 0 && real(z) < 2)
        outputBits(1) = 1;
        outputBits(2) = 1;
    endif
    
    if (real(z) >= 2)
        outputBits(1) = 1;
        outputBits(2) = 0;
    endif



    if (imag(z) < -2)
        outputBits(3) = 0;
        outputBits(4) = 0;
    endif
    
    if (imag(z) >= -2 && imag(z) < 0)
        outputBits(3) = 0;
        outputBits(4) = 1;
    endif
    
    if (imag(z) >= 0 && imag(z) < 2)
        outputBits(3) = 1;
        outputBits(4) = 1;
    endif
    
    if (imag(z) >= 2 )
        outputBits(3) = 1;
        outputBits(4) = 0;
    endif

endfunction