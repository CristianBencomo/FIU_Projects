library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity CodeDetector is 
    Port (  clk : in std_logic;
            reset : in std_logic;
            r : in std_logic; 
            g : in std_logic;
            b : in std_logic;
            lock : out std_logic;
            d : out std_logic);
end CodeDetector;

architecture Behavioral of CodeDetector is
type statetype is (idle, red1, green, blue, red2);
signal state : statetype;
begin

    --State Register
    process (clk, reset, r, g, b) begin
        if (reset = '0') then state <= idle;
        elseif rising_edge(clk) then
            case (state) is
                
                when idle => 
                    if (r='0') then state <= red1;
                    end if;

                when red1 =>
                if (b='0') then state <= blue;
                elseif (r='0') then state <= red1
                elseif (g='0') then state <= idle;
                end if;

                when blue =>
                if (g='0') then state <= green;
                elseif (b='0') then state <= blue;
                elseif (g='0') then state <= idle;
                end if;

                when green =>
                if (r='0') then state <= red2;
                elseif (g='0') then state <= green
                elseif (b='0') then state <= idle;
                end if;

                when red2 =>
                    state <= red2;
                when others
                    state <= idle;
            
            end case;
        end if;
    end process;

    -- output
    lock <= '1' when state = red2 else '0';
    d <= '1' when state = idle else '0'

end Behavioral;

            


