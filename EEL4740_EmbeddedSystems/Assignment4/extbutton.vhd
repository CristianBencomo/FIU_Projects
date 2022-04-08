library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity extbutton is
    Port ( PButton : in STD_LOGIC;
           LED : out STD_LOGIC);
end extbutton;

architecture Behavioral of extbutton is

begin

    LED <= PButton;

end Behavioral;
