class Lanalysis
{
	public int Ana(String lada){
	parser john = new parser();
// location of the tokens
	String[] Tokes = new String[30];
	String temp = "";
	int ce;
	int TokensTally = 0;
	
	for(String Tokens: lada.split(" ")){
	// disregards the space between tokens
	temp = temp + Tokens;
	}
	// split no space string
	for(String ra: temp.split("")){
	Tokes[TokensTally] = ra;
	TokensTally +=1;
	}
	return john.ser(Tokes, TokensTally);
}

}