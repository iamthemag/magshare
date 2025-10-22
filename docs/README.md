# MagShare Website

This directory contains the GitHub Pages website for MagShare.

## Enabling GitHub Pages

To enable GitHub Pages for this repository:

1. Go to your repository on GitHub
2. Navigate to **Settings** → **Pages**
3. Under "Source", select:
   - **Branch**: `main` (or `master`)
   - **Folder**: `/docs`
4. Click **Save**

GitHub will build and deploy your site at: `https://iamthemag.github.io/magshare/`

## Features

- ✅ Fully responsive design (mobile, tablet, desktop)
- ✅ Hamburger menu for mobile navigation
- ✅ Automatic download buttons that fetch the latest release from GitHub API
- ✅ Smooth scrolling and modern animations
- ✅ Clean, professional design

## Files

- `index.html` - Main HTML page
- `styles.css` - Responsive CSS with mobile-first design
- `script.js` - JavaScript for menu toggle and GitHub API integration
- `_config.yml` - GitHub Pages configuration

## Local Testing

To test the site locally:

1. Open `index.html` in your web browser
2. Or use a local server:
   ```bash
   # Python 3
   python -m http.server 8000
   
   # Node.js (if you have http-server installed)
   npx http-server
   ```
3. Navigate to `http://localhost:8000`

## Customization

### Updating Colors
Edit the CSS variables in `styles.css`:
```css
:root {
    --primary-color: #4a90e2;
    --secondary-color: #2c3e50;
    --accent-color: #e74c3c;
}
```

### Adding Content
Edit `index.html` to add new sections or modify existing content.

### Modifying Download Logic
The download buttons automatically detect the latest release. The logic is in `script.js`:
- Fetches from: `https://api.github.com/repos/iamthemag/magshare/releases/latest`
- Matches files by extension: `.exe` (Windows), `.deb` (Linux), `.dmg` (macOS)

## Logo

The site references the logo at `../MagShare-logo.png`. Make sure this file exists in the repository root, or update the path in `index.html`.

## Maintenance

The site will automatically show the latest release version and download links. No manual updates needed when you publish new releases!
