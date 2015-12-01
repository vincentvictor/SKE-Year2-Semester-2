package strategy;

public class SoccerTeam {
	public void execStrategy(Strategy s) {
		s.exec();
	}
	public static void main(String[] args) {
		SoccerTeam st = new SoccerTeam();
		st.execStrategy(new OffensiveStrategy());
		st.execStrategy(new DefensiveStrategy());
		
	}
}
