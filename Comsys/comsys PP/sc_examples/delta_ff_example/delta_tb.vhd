library ieee;
use ieee.std_logic_1164.all ;
use ieee.std_logic_unsigned.all ;

entity delta_tb is
end delta_tb;

architecture htwtestbench of delta_tb is

component delta
    port (clk       : in std_logic; 
         din        : in std_logic;   
         dout       : out std_logic);
end component;

signal clk_s        : std_logic:='0'; 
signal din_s        : std_logic;   
signal dout_s       : std_logic;   


begin

dut : delta port map (clk => clk_s,
                    din => din_s,
                    dout => dout_s);
                              
              
clk_s <= not clk_s after 5 ns;

process
  begin
    din_s   <= '0';
    wait for 31 ns;
    din_s <= '1';       
    wait for 31 ns;
    din_s   <= '0';

    wait;
end process;

end htwtestbench;
