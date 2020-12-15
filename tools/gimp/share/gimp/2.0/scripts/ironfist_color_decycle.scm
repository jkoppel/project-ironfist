(define (ironfist_color_decycle_replace
        img
		drawable
		col
        col2)

	(gimp-selection-none img)
		
	(gimp-image-select-color img 0 drawable col)

	(if (= (car (gimp-selection-is-empty img)) TRUE)
		()
		(begin (gimp-context-set-foreground col2) (gimp-edit-fill drawable 0))
	)
)

(define (ironfist_color_decycle
        img
        drawable)

	(gimp-image-undo-group-start img)
	
	(gimp-context-set-sample-threshold-int 0)
	(gimp-context-set-antialias 0)
	(gimp-context-set-feather 0)
	(gimp-context-set-sample-merged 0)
	(gimp-context-set-sample-criterion 0)
	(gimp-context-set-sample-transparent 0)
	
	(ironfist_color_decycle_replace img drawable '(255 62 0) '(189 84 0))	
	(ironfist_color_decycle_replace img drawable '(237 18 0) '(166 74 0))
	(ironfist_color_decycle_replace img drawable '(203 0 0) '(148 59 0))
	(ironfist_color_decycle_replace img drawable '(170 0 0) '(126 48 0))
	(ironfist_color_decycle_replace img drawable '(250 254 0) '(238 206 34))
	(ironfist_color_decycle_replace img drawable '(255 196 0) '(234 197 0))
	(ironfist_color_decycle_replace img drawable '(194 127 0) '(178 128 0))
	(ironfist_color_decycle_replace img drawable '(139 59 0) '(148 59 0))	
	(ironfist_color_decycle_replace img drawable '(0 109 209) '(91 107 209))	
	(ironfist_color_decycle_replace img drawable '(0 93 196) '(76 91 195))
	(ironfist_color_decycle_replace img drawable '(0 61 178) '(56 64 178))
	(ironfist_color_decycle_replace img drawable '(0 46 170) '(36 42 161))
	(ironfist_color_decycle_replace img drawable '(0 73 187) '(66 76 187))
	(ironfist_color_decycle_replace img drawable '(87 222 255) '(151 245 254))
	(ironfist_color_decycle_replace img drawable '(0 142 255) '(122 140 226))
	(ironfist_color_decycle_replace img drawable '(0 67 234) '(76 91 195))
	(ironfist_color_decycle_replace img drawable '(15 0 161) '(27 33 139))
	
	(gimp-image-undo-group-end img)
	(gimp-displays-flush)   
)

(script-fu-register "ironfist_color_decycle"
    "<Image>/Script-Fu/Ironfist/Ironfist Color Decycle"
    "Replace all cycled colors to similar looking static ones"
    "Kert"
    "Kert"
    "2020"
    "*"
    SF-IMAGE    "Image"         0
    SF-DRAWABLE "Current Layer" 0
)