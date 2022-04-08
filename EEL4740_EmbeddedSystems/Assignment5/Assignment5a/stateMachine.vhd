library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity stateMachine is
    Port  ( clk : in std_logic;
            reset : in std_logic;
            a : in std_logic;
            y : out std_logic);
end stateMachine;

architecture Behavioral of stateMachine is
type statetype is (zero. one, two, three);
signal state statetype;
begin
    process (clk, reset)
    begin
        --State Register
        if (reset = '0') then state <= zero;
        elseif rising_edge(clk) then
            
            case (state) is 
            
            when zero => 
            if (a = '1') then state <= one;
            elseif (a = '0') then state <= zero;
            end if;
            
            when one => 
            if (a = '1') then state <= two;
            elseif (a = '0') then state <= zero;
            end if;

            when two => 
            if (a = '1') then state <= two;
            elseif (a = '0') then state <= zero;
            end if;

            when three => 
            if (a = '1') then state <= zero;
            elseif (a = '0') then state <= zero;
            end if;

            end case;
        end if;
    end process;

    --output logic
    y <= '1' when state = one else '0'
  
end Behavioral;
