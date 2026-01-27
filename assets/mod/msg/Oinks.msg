#message:05:(Oinks_Gold) {
	[Style narrate]
	[DelayOff]
	[SetPosX 50][Down 6]It's a Gold Li'l-Oink![BR]
	[SetPosX 40]Look at its golden hide![BR]
	[SetPosX 35]It glows like a treasure![DelayOn][Wait][End]
}

#message:05:(Oinks_Paused) {
	[Style sign]
	[DelayOff]
	[Down 2][SetPosX 48]You have suspended[BR]
	[Down 2][SetPosX 12]the hatching of the Lil-Oinks...[BR]
	[Down 2][SetPosX 48]To resume, press [Z][BR][DelayOn][Wait][End]
}

#message:05:(Oinks_Multihatch) {
	[Style sign]
	[DelayOff]
	[Down 16][Right 30]Hatch multiple Li'l-Oinks?[DelayOn][Yield][End]
}

#message:05:(Oinks_Multihatch_Choice) {
	[Style choice pos=60,105 size=200,95]
	[DelayOff]
	[Cursor 0][Option 0]Hatch 5 Li'l-Oinks.[BR]
	[Cursor 1][Option 1]Hatch 10 Li'l-Oinks![BR]
	[Cursor 2][Option 2]Hatch 20 Li'l-Oinks![BR]
	[Cursor 3][Option 3]Hatch 50 Li'l-Oinks![BR]
	[Cursor 4][Option 4]Never mind...[BR]
	[Option 255][DelayOn]
	[EndChoice 5][End]
}
