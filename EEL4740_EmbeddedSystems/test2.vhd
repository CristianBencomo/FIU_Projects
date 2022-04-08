library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity xcode is
    Port  ( binary : in STD_LOGIC_VECTOR (2 downto 0);
    xcode :out STD_LOGIC_VECTOR (2 downto 0));
end xcode;

architecture Behavioral of xcode is
begin

    process (binary)
    begin
    
        case (binary) is
           when "000" => xcode <= "000";
           when "001" => xcode <= "001";
           when "010" => xcode <= "011";
           when "011" => xcode <= "010";
           when "100" => xcode <= "110";
           when "101" => xcode <= "111";
           when "110" => xcode <= "101";
           when "111" => xcode <= "100";
           when others => xcode <= binary; -- I left the xcode = binaty when the case was not specified.
            
        end case;
    end process;
 
  
end Behavioral;
