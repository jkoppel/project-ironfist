structure Main_HvMM = Referee(struct
                                    structure Maxie  = HumanPlayer(Gom) 
                                    (*                              structure Maxie = MiniMax(Gom) *)
                                    (*                              structure Minnie  = HumanPlayer(Gom) *)
                                    structure Minnie = MiniMax(Gom)
                                end)

structure Main_HvJ = Referee(struct
                                 structure Maxie  = HumanPlayer(Gom)
                                 structure Minnie = Jamboree(Gom)
                             end)

structure Main_MMvJ = Referee(struct
                                  structure Maxie  = MiniMax(Gom)
                                  structure Minnie = Jamboree(Gom)
                              end)

structure MMvMM = Referee(struct
                              structure Maxie  = MiniMax(Gom)
                              structure Minnie = MiniMax(Gom)
                          end)

structure JvJ = Referee(struct
                            structure Maxie  = Jamboree(Gom)
                            structure Minnie = Jamboree(Gom)
                        end)

structure Main_JvH = Referee(struct
                                 structure Maxie  = Jamboree(Gom)
                                 structure Minnie = HumanPlayer(Gom)
                             end)

