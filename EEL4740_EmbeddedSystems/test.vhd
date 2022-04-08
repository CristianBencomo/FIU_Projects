library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity logiccircuit is
    Port  ( a : in STD_LOGIC;
    b : in STD_LOGIC;
    c : in STD_LOGIC;
    z : out STD_LOGIC;
    y :out STD_LOGIC);
end logiccircuit;

architecture Behavioral of logiccircuit is
begin

  z <= a and c;
  y <= (a xor b) and not c;
  
end Behavioral;
