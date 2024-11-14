import React from "react";

import { Avatar, Typography, Box } from "@mui/material";
import '@fontsource/roboto/300.css';
import '@fontsource/roboto/400.css';
import '@fontsource/roboto/500.css';
import '@fontsource/roboto/700.css';

const Header = () => {
  return(

  <Box
  sx={{
    display: 'flex',
    alignItems: 'center',
    justifyContent: 'space-between',
    padding: '10px 20px',
    color: '#fff',
  }}
>
  {/* Project Name */}
  <Typography variant="h4" component="div" sx={{ fontWeight: 'bold' }}
   style={{ fontFamily: 'Poppins, sans-serif' }}>
    Forest Protection System
  </Typography>

  {/* Avatar Section */}
  <Box sx={{ display: 'flex', gap: '10px' }}>
    <Avatar sx={{ bgcolor: '#3498db' }}>S</Avatar>
    <Avatar sx={{ bgcolor: '#e74c3c' }}>V</Avatar>
  </Box>
</Box>
);
}

export default Header