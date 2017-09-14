local AdvMessageBox = {}

function AdvMessageBox.Normal(text)
	AdvancedMessageBox(text, 1, -1, -1, -1, 0, -1, 0, -1, 0)
	end; 
	
function AdvMessageBox.SingleImage(text, dialogtype, img1type, img1arg)
	AdvancedMessageBox(text, dialogtype, -1, -1, img1type, img1arg, -1, 0, -1, 0)

end;

function AdvMessageBox.DoubleImage(text, dialogtype, img1type, img1arg, img2type, img2arg)
	
	AdvancedMessageBox(text, dialogtype, -1, -1, img1type, img1arg, img2type, img2arg, -1, 0)

end;


return AdvMessageBox