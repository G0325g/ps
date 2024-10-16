SELECT count(*) as FISH_COUNT from fish_info fi left outer join fish_name_info fn on 
fi.Fish_type = fn.fish_type
where fish_name = 'BASS' or fish_name = "SNAPPER";