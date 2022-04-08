library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity Proc_Counter is
    Port ( clk : in  STD_LOGIC;
           reset : in  STD_LOGIC;
           B : in  STD_LOGIC;
           D : in  STD_LOGIC;
           C : out  STD_LOGIC_VECTOR (7 downto 0));
end Proc_Counter;

architecture Behavioral of Proc_Counter is
type statetype is (start, Swait, count, Bwait, subtract, Dwait);
signal state, nextstate: statetype;

signal counter, counternext: STD_LOGIC_VECTOR (7 downto 0);

begin
--state register
    process(clk, reset) 
    begin
        if(reset ='1') then
            state <= start;
            counter <= "00000000";
        elsif rising_edge(clk) then
            state <= nextstate;
            counter <=counternext;
        end if;
    end process;

--combinational logic
process(state, B)
begin 
    case (state) is
        
        when start =>
        counternext <="00000000";
        nextstate <= Swait;

        when Swait =>
        counternext <=counter;
        if (B='1') then
            nextstate <= count;
        elsif (D='1') then
            nextstate <= subtract;
        else
            nextstate<= Swait;
        end if;

        when count =>
        counternext <= counter + 1;
        nextstate <= Bwait;
        
        when subtract =>
        counternext <= counter - 1;
        nextstate <= Dwait;

        when Bwait =>
        counternext <=counter;
        if (B='1') then
            nextstate <= Bwait;
        else
            nextstate<= Swait;
        end if;
        
        when Dwait =>
        counternext <=counter;
        if (D='1') then
            nextstate <= Dwait;
        else
            nextstate<= Swait;
        end if;

    end case;
end process;

C <= counter;

end Behavioral;

