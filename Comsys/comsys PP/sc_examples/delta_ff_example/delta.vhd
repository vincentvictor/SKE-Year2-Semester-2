--
-- Simple delta test
--

library ieee;
use ieee.std_logic_1164.all ;
use ieee.std_logic_unsigned.all ;

entity delta is
   port (clk    : in  std_logic; 
         din    : in  std_logic; 
         dout   : out std_logic);  
end delta;

architecture rtl of delta is 
  
signal q_s      : std_logic:='0';
signal clk_s    : std_logic;

begin
    
   process (clk)        
    begin
        if rising_edge(clk) then  
            q_s <= din;
        end if ;
    end process ;
 
    clk_s <= clk;       -- Introduce delta delay

   process (clk_s)          
     begin
        if rising_edge(clk_s) then  
            dout <= q_s;
        end if ;
    end process;

end rtl;
