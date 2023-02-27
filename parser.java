class parser
{

 public int ser(String[] Ea, int totoks){
			  
	int ctr = 0;
	int proceed = 0;
	int paren = 0;
	int thesis = 0;
	int x = 2;
	if(Ea[0].equals("A") || Ea[0].equals("B") || Ea[0].equals("C")){
				  proceed += 1;
				  if(Ea[1] != null)
				  {
                      if(Ea[1].equals("="))
					  {
						   proceed += 1;
						   if(Ea[2] != null)
						   {
							  
								do
								{
                                  //ID's
								 if(Ea[x].equals("A")||Ea[x].equals("B") || Ea[x].equals("C"))
										{
										
									     if(Ea[x + 1] == null)
										 {
											 proceed += 1;
										 }
										 else{
										 if(Ea[x + 1].equals("+") || Ea[x + 1].equals("-"))
										 {
											 proceed +=1 ;
										 }
                                         if(Ea[x + 1].equals("*") || Ea[x + 1].equals("/"))
										 {
											 proceed +=1 ;
										 }
                                        if(Ea[x + 1].equals(")"))
											{
												proceed +=1;
												
											}  
									    
											
										 }										 
										}
										//Parenthesis
										if(Ea[x].equals("("))
										{
										  if(Ea[x + 1].equals("A") || Ea[x + 1].equals("B") || Ea[x+1].equals("C"))
										  {
											  proceed +=1;
											  paren +=1;
											  
										  }
										  if(Ea[x+1].equals("("))
										  {
											  
											  proceed+=1;
											  paren+=1;
											  
										  }
										   if(Ea[x +1].equals("1") || Ea[x +1  ].equals("2") || Ea[x +1  ].equals("3") || Ea[x + 1].equals("4") || Ea[x + 1].equals("5") || Ea[x + 1].equals("6") || Ea[x + 1].equals("7") || Ea[x + 1].equals("8") || Ea[x + 1].equals("9") || Ea[x +1].equals("0"))										 
										  {
											  proceed +=1;
											  paren+=1;
										  }	 
											
										}
										if(Ea[x].equals(")"))
										{
											if(Ea[x + 1] == null)
											{
												proceed +=1;
												thesis+=1;
												
											}
											else
											{
											if(Ea[x + 1].equals(")"))
											{
												proceed +=1;
												thesis +=1;
												
											}
											 if(Ea[x + 1].equals("+") || Ea[x + 1].equals("-"))
										    {
											 proceed +=1 ;
											 thesis +=1;
										    }
                                             if(Ea[x + 1].equals("*") || Ea[x + 1].equals("/"))
										    {
											
											 proceed +=1 ;
											 thesis+=1;
										    }	
                                											
											}
												
										}
										//Expr
                                        if(Ea[x].equals("+") || Ea[x].equals("-"))
                                        {
											if(Ea[x + 1].equals("A") || Ea[x + 1].equals("B") || Ea[x+1].equals("C"))
											{
												proceed +=1;
												
											}
											if(Ea[x + 1].equals("("))
											{
											    proceed +=1;
											}
											 if(Ea[x +1].equals("1") || Ea[x +1  ].equals("2") || Ea[x +1  ].equals("3") || Ea[x + 1].equals("4") || Ea[x + 1].equals("5") || Ea[x + 1].equals("6") || Ea[x + 1].equals("7") || Ea[x + 1].equals("8") || Ea[x + 1].equals("9") || Ea[x +1].equals("0"))										 
										  {
											  proceed +=1;
										  }	 
											
										}
										//term
                                        if(Ea[x].equals("*") ||Ea[x].equals("/"))
										{
											if(Ea[x + 1].equals("A") || Ea[x + 1].equals("B") || Ea[x+1].equals("C"))
											{
												proceed +=1;
												
											}
											if(Ea[x + 1].equals("("))
											{
											    proceed +=1;
											}
											 if(Ea[x +1].equals("1") || Ea[x +1  ].equals("2") || Ea[x +1  ].equals("3") || Ea[x + 1].equals("4") || Ea[x + 1].equals("5") || Ea[x + 1].equals("6") || Ea[x + 1].equals("7") || Ea[x + 1].equals("8") || Ea[x + 1].equals("9") || Ea[x +1].equals("0"))										 
										  {
											  
											  proceed +=1;
										  }	 
										}
										//digits
									    if(Ea[x].equals("1") || Ea[x ].equals("2") || Ea[x].equals("3") || Ea[x ].equals("4") || Ea[x].equals("5") || Ea[x ].equals("6") || Ea[x].equals("7") || Ea[x].equals("8") || Ea[x].equals("9") || Ea[x].equals("0"))
                                 		{
											if(Ea[x + 1] == null)
										 {
											 
											 proceed += 1;
										 }
										 else{
										 if(Ea[x + 1].equals("+") || Ea[x + 1].equals("-"))
										 {
											 proceed +=1 ;
										 }
                                         if(Ea[x + 1].equals("*") || Ea[x + 1].equals("/"))
										 {
											 proceed +=1 ;
										 }
                                          if(Ea[x +1].equals("1") || Ea[x +1  ].equals("2") || Ea[x +1  ].equals("3") || Ea[x + 1].equals("4") || Ea[x + 1].equals("5") || Ea[x + 1].equals("6") || Ea[x + 1].equals("7") || Ea[x + 1].equals("8") || Ea[x + 1].equals("9") || Ea[x +1].equals("0"))										 
										  {
											  proceed +=1;
										  }
                                   		 if(Ea[x + 1].equals(")"))
										  {
												proceed +=1;
												
										  }										  
									 }		
										}							   
									x +=1;
								} while(x < totoks);
                            }
                           else
                           {
							   proceed -= 1;
						   }							   
					  }		 
			   }
			   else
			   {
				   proceed -= 1;
			   }
			 
			    
			   
			  }
			 
	      if( proceed == totoks && paren == thesis){
				  
				   return 1;
		    }
		  else
		  {
                  return 2;
		  }			  

}
}