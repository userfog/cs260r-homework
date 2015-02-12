(* Frama-C journal generated at 07:43 the 11/02/2015 *)

exception Unreachable
exception Exception of string

(* Run the user commands *)
let run () =
  Dynamic.Parameter.StringList.set "" [ "sat_ops_old.c" ];
  File.init_from_cmdline ();
  Project.clear
    ~selection:(State_selection.of_list
                  [ State.get "Report.print_once";
                    State.get "Property_status.Valid_cycles";
                    State.get "Property_status.Hypotheses";
                    State.get "Consolidation graph";
                    State.get "Consolidated_status";
                    State.get "Call Preconditions Generated" ])
    ~project:(Project.from_unique_name "default")
    ();
  Project.clear
    ~selection:(State_selection.of_list
                  [ State.get "Report.print_once";
                    State.get "Property_status.Valid_cycles";
                    State.get "Property_status.Hypotheses";
                    State.get "Consolidation graph";
                    State.get "Consolidated_status";
                    State.get "Call Preconditions Generated" ])
    ~project:(Project.from_unique_name "default")
    ();
  Project.clear
    ~selection:(State_selection.of_list
                  [ State.get "Report.print_once";
                    State.get "Property_status.Valid_cycles";
                    State.get "Property_status.Hypotheses";
                    State.get "Consolidation graph";
                    State.get "Consolidated_status";
                    State.get "Call Preconditions Generated" ])
    ~project:(Project.from_unique_name "default")
    ();
  ()

(* Main *)
let main () =
  Journal.keep_file "frama_c_journal.ml";
  try run ()
  with
  | Unreachable -> Kernel.fatal "Journal reachs an assumed dead code" 
  | Exception s -> Kernel.log "Journal re-raised the exception %S" s
  | exn ->
    Kernel.fatal
      "Journal raised an unexpected exception: %s"
      (Printexc.to_string exn)

(* Registering *)
let main : unit -> unit =
  Dynamic.register
    ~plugin:"Frama_c_journal"
    "main"
    (Datatype.func Datatype.unit Datatype.unit)
    ~journalize:false
    main

(* Hooking *)
let () = Cmdline.run_after_loading_stage main; Cmdline.is_going_to_load ()
