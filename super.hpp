



void createNewPlatform(list& platforms)
{
	platforms.push_back(new_platfrom);
	thesuperclass.createNewPlatform();
	n_platforms ++;

}



main(){

	game.update();

}
